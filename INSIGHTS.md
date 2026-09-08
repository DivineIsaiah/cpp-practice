# Insights

Two parts: a security check on the repo as cloned, and an honest read of the code that is
already in it.

---

## Part 1: Security scan (clean)

Scanned at clone time, commit `cfd1721`, 30 tracked files, 6 commits, single remote
`https://github.com/DivineIsaiah/cpp-practice`.

| Check | Result |
|---|---|
| Git hooks (`.git/hooks`) | Empty. No hooks installed, nothing runs on checkout or commit. |
| Submodules / `.gitmodules` | None. |
| Symlinks, binaries, executables | None. Every tracked file is plain `.cpp` text plus `.gitignore`. |
| Process execution (`system`, `exec*`, `popen`, `fork`, `CreateProcess`, `ShellExecute`, `WinExec`) | No matches. |
| Network (`socket`, `curl`, `wget`, any `http://` or `https://` literal) | No matches. |
| Filesystem destruction (`remove`, `unlink`, `rmdir`, `format`) | No matches. |
| Persistence (`reg add`, `schtasks`, startup paths) | No matches. |
| Dynamic loading (`LoadLibrary`, `GetProcAddress`, `.dll`) | No matches. |
| Encoded / obfuscated payloads (base64 blobs, long hex strings) | None. |
| Includes | Only `<iostream>` and `<string>` across every file. |
| Build config that could run arbitrary commands (Makefile, CMakeLists, `.vscode/tasks.json`, CI workflows) | None present. `.vscode/` is gitignored. |

Nothing in this repo executes anything on clone or on open. The only way any of it runs is
if you compile a `.cpp` yourself and run the binary, and the worst any of those binaries
currently does is print text and read `cin`.

**Keep it that way.** Since this repo is shared, before you compile anything your friend
pushed, run:

```bash
git log -p HEAD..origin/main
```

That shows every incoming line before you build it. The realistic risk in a shared practice
repo is not clever malware, it is one of you pasting a snippet that includes `system(...)`
from a random tutorial. Grep for it after each pull:

```bash
grep -rniE "system\(|exec|popen|socket|curl|wget|http" --include=*.cpp .
```

---

## Part 2: Code review of what is already here

The overall shape is good. The linked list work in `LinkedLists/q1.cpp` is genuinely
solid, well past what most people at the loops-and-arrays stage have written. But there
are real bugs, and a few of them are the kind that lose marks in an exam.

### Actual bugs, fix these first

1. **`Functions/greet.cpp` line 15: `cube()` returns the square.**
   ```cpp
   int cube(int number) { return number * number; }
   ```
   `cube(56)` prints 3136, not 175616. It needs `number * number * number`. Nothing in the
   output looks wrong, which is exactly why this kind of bug survives.

2. **`Functions/greet.cpp`: `showMarks(marks, 4)` silently drops the last mark.**
   The array has 5 elements. Passing a hardcoded size that does not match the array is the
   single most common array bug there is. Either pass `5`, or compute
   `sizeof(marks)/sizeof(marks[0])` at the call site (it does not work inside the function,
   because the array decays to a pointer there, which is worth knowing).

3. **`LinkedLists/q1.cpp`: `inserAtPosition` dereferences null on an empty list.**
   If `head == nullptr` and `position != 1`, the code reaches `while (temp->next != nullptr)`
   with `temp == nullptr` and crashes. Add an empty-list guard at the top. Also, the name is
   missing a `t`: `insertAtPosition`.

4. **`IfElse/grade.cpp`: the `score < 0` branch is unreachable.**
   `else if (score < 40)` comes first and swallows every negative number, so `-50` prints
   grade F instead of "invalid". Validate the range once, up front:
   ```cpp
   if (score < 0 || score > 100) { /* invalid */ }
   else if (score >= 70) { ... }
   ```
   Same file: `"You're grade is A"` should be `"Your"`. Small, but it is on screen.

5. **`IfElse/largest.cpp`: ties are reported as invalid input.**
   `5 5 3` fails all three strict `>` comparisons and falls into
   `"That doesn't seem valid"`. Use `>=` in the comparisons, or restructure as
   `int max = num1; if (num2 > max) max = num2; ...` which is shorter and cannot have this
   bug.

6. **`Arrays.cpp`: the linear search prints nothing when the value is absent.**
   The loop only prints on a hit. Use a `bool found = false;` flag, or track the index and
   report after the loop.

7. **`IfElse/minororadult.cpp`: the final `else` is unreachable** (the three prior branches
   cover every int), and a negative age is classified as a child. Same fix as #4: validate
   before branching.

8. **`IfElse/vowelorconsonant.cpp`: missing spaces in the output.**
   `"The alphabet" << alphabet << "is a vowel."` prints `The alphabetais a vowel.`

9. **`Loops/star.cpp` prints digits, not stars.** The inner loop does `cout << p;` so you
   get `1`, `12`, `123`. If the exercise wanted a star triangle, print `'*'`.

### Habits worth changing now, before they harden

10. **Every `cin >>` in this repo can be broken by typing a letter.**
    Type `abc` at any numeric prompt: the stream fails, the variable stays 0 or garbage, and
    every later `cin` is skipped, so the program stampedes to the end printing nonsense.
    `Loops/password.cpp` is the only one that is genuinely safe, because it reads a string.
    This is question 68 in [QUESTIONS.md](QUESTIONS.md), and it is worth doing once properly
    and then reusing:
    ```cpp
    int readInt(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            if (cin >> value) return value;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was not a number. Try again.\n";
        }
    }
    ```

11. **Array sizes are hardcoded in six different places in `Arrays.cpp`.**
    `for (int i = 0; i < 7; i++)` works until someone adds a name. Declare
    `const int SIZE = 7;` next to the array and use it everywhere, or
    `sizeof(arr)/sizeof(arr[0])`. The bubble sorts do this correctly with `n`, `qnt`, `sz`,
    so the good habit is already half there. The other half is that `for (int i = 0; i < 7; i++)`
    on `names` and `for (int i = 0; i < 10; i++)` on `numbers` are the loose ends.

12. **`cin >> name` cannot read "Divine Isaiah".** It stops at whitespace, and the leftover
    ` Isaiah` sits in the buffer and gets eaten by the *next* `cin`, which is why
    `Functions/sim.cpp` and `IfElse/minororadult.cpp` go strange if anyone types two words.
    `getline(cin, name)` is the fix, with a `cin.ignore()` after any preceding `cin >>`.

13. **Globals in `Functions/sim.cpp` and `Loops/table.cpp`.**
    `string name; string sex;` at file scope works, but it means `welcome()` and `goodbye()`
    only ever work on those specific variables. Pass parameters and return values instead.
    Many lecturers explicitly ban globals in linked list questions (`q1.cpp` already respects
    that, and the comment in `main` says so).

14. **Nothing is ever `delete`d except in `q1.cpp`.**
    `LinkedLists/independent.cpp` and `LinkedLists/nodes.cpp` allocate with `new` and never
    free. The OS reclaims it at exit so you will not notice, but "every `new` needs a
    matching `delete`" is a standard exam question and a standard mark. `q1.cpp`'s
    `deleteList` is the right pattern; call something like it at the end of the others.

15. **`LinkedLists/independent.cpp`: the local variable shadows the function.**
    ```cpp
    Node* newNode (int value) { Node* newNode = new Node(); ... }
    ```
    This compiles, but inside the body `newNode` now means the pointer, not the function, so
    it cannot call itself and any reader has to stop and work out which is which. Name the
    function `createNode` (as `nodes.cpp` and `q1.cpp` already do) and keep the naming
    consistent across all three files. Also, the stray `;` after the function's closing brace
    is harmless but wrong.

16. **`q1.cpp`: `reverse()` calls `traverse()` inside itself.**
    A function that reverses should reverse, not print. Right now you cannot reverse a list
    without also dumping it to the screen. Separate them, and call `traverse(head)` from
    `main`. Same idea applies to the `cout` inside `deleteEnd` and `deleteBegining`: fine for
    practice, but the reusable version returns `bool` and lets the caller decide what to say.

17. **`Algorithms.cpp`: `mid` is computed in three places.**
    The logic is correct, but recomputing `mid` inside each branch means there are three
    places to get it wrong. Compute it once at the top of the `while` body:
    ```cpp
    while (low <= high) {
        int mid = low + (high - low) / 2;
        ...
    }
    ```
    The `low + (high - low) / 2` form is the standard fix for the integer overflow in
    `(low + high) / 2`. It cannot bite you at n = 9, but it is a known interview question.
    Also `sizeOFarray = 9` is hardcoded next to a 9-element array again, see #11.

18. **`using namespace std;` in every file.** Fine for practice and coursework. Worth
    knowing that it is discouraged in real projects, and why, before someone asks you in a
    viva.

### Empty files

`Pointers.cpp`, `Structures.cpp` and `Variables.cpp` are 0 bytes. Sections 1, 7 and 8 of
[QUESTIONS.md](QUESTIONS.md) are aimed at those three, and pointers in particular is the
topic that decides whether the linked list material actually clicks or stays memorised.

### What is already good

- `q1.cpp` handles empty list, single node, and not-found cases in `deleteEnd`,
  `deleteBegining` and `delhelper`. That defensive instinct is the thing most people lack.
- Splitting `search`/`searchNode` and `delhelper`/`deleteNode` into a compute function and a
  print function is a real design decision, and it is the right one. Apply it to `reverse`
  too (#16).
- The descending bubble sort on `floip` is a genuine variation, not a copy of the ascending
  one, which shows the mechanism is understood rather than remembered.
- The comment in `independent.cpp` about wanting `newNode(10, 20, 30, 40)` is the right
  question to be asking. The answer is variadic arguments or an array parameter, and it is
  worth building once the basics are locked in.

---

## Suggested order of work

1. Fix bugs 1 through 9. They are small and each one takes minutes.
2. Write `readInt` once (#10) and retrofit it into `grade.cpp`, `sum.cpp`, `table.cpp` and
   `Algorithms.cpp`.
3. Fill `Variables.cpp`, then `Pointers.cpp`, then `Structures.cpp` from sections 1, 8 and 7.
4. Then the `[stretch]` linked list questions, 63 to 67. Everything before them is already
   in reach.
