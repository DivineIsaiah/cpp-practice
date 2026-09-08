# C++ Practice Questions

Shared question bank. Working style: whoever posts a question adds it under the right
section with a difficulty tag. Whoever solves it commits the solution as a `.cpp` file
in the matching folder and links it back here.

Difficulty tags: `[warm]` `[core]` `[stretch]`

---

## 1. Basics and Variables

1. `[warm]` Declare an `int`, a `double`, a `char`, a `bool` and a `string`. Print each one with a label. Then print `sizeof` each and explain why `bool` is not 1 bit.
2. `[warm]` Ask for a full name using `cin >> name`, then again using `getline(cin, name)`. Type "Divine Isaiah" into both. Explain the difference in output.
3. `[core]` Swap two integers without using a third variable.
4. `[core]` Read a temperature in Celsius as a `double` and print Fahrenheit to 2 decimal places. Then read it as an `int` and show what precision you lose.
5. `[stretch]` What does `int x = 7 / 2 * 2.0;` hold, and why? Predict before compiling.

## 2. If / Else and Logic

6. `[warm]` Read a number, print whether it is positive, negative, or zero.
7. `[warm]` Read three numbers and print the largest. Make ties work: `5 5 3` should print 5, not an error.
8. `[core]` Grade calculator: A >= 70, B 60-69, C 50-59, D 45-49, E 40-44, F below 40. Reject scores below 0 or above 100 *before* grading, not after.
9. `[core]` Leap year checker written as a single boolean expression instead of nested ifs. Compare the two versions for readability.
10. `[core]` Vowel or consonant, but also reject input that is not a letter at all (digits, punctuation, spaces).
11. `[stretch]` Simple calculator: read `num1 op num2` where op is `+ - * / %`. Handle divide-by-zero and unknown operators. Use a `switch`.
12. `[stretch]` Read a character and classify it as uppercase letter, lowercase letter, digit, or symbol, without using `<cctype>`.

## 3. Loops

13. `[warm]` Print 1 to 20, then 20 down to 1.
14. `[warm]` Print all even numbers 1-50 on one line, all odd numbers on the next.
15. `[core]` Multiplication table for a number the user enters, 1 through 12, aligned in neat columns.
16. `[core]` Sum of 1..n, then the factorial of n. Note the value of n where factorial overflows an `int`.
17. `[core]` Password loop that allows only 3 attempts before locking out. Print how many attempts remain each time.
18. `[core]` Print this pattern for n = 5, then the inverted version, then a centred pyramid:

    ```
    *
    **
    ***
    ****
    *****
    ```

19. `[core]` Reverse the digits of an integer using only `%` and `/`. `1234` becomes `4321`.
20. `[stretch]` Check whether a number is prime, then print all primes below 100.
21. `[stretch]` Print the first 15 Fibonacci numbers with a loop (no recursion).
22. `[stretch]` Read numbers until the user enters `-1`. Print the count, sum, average, min and max of everything before the sentinel.

## 4. Functions

23. `[warm]` Write `int square(int)` and `int cube(int)`. Verify that `cube(3) == 27`.
24. `[core]` Write `int biggest(int, int, int)` that returns the largest of three, reusing a two-argument `bigger()` internally.
25. `[core]` Write `void printArray(int arr[], int size)` and prove it prints every element when called with the real array size.
26. `[core]` Write `bool isPrime(int)` and use it inside a loop to print primes below 100.
27. `[core]` Write `int sumArray(int arr[], int size)` and `double averageArray(int arr[], int size)`. Make the average come out as a decimal, not truncated.
28. `[stretch]` Write `void swap(int& a, int& b)` using references, then the same thing using pointers. Explain when you would pick each.
29. `[stretch]` Overload `area()` for a circle (one double), a rectangle (two doubles) and a triangle (base, height). Explain how the compiler picks.
30. `[stretch]` Write a recursive `factorial()` and an iterative one. Which one dies first on large input, and why?

## 5. Arrays

31. `[warm]` Build an array of 7 names, replace two of them, print all 7 in a loop.
32. `[core]` Find the largest and smallest element in one single pass.
33. `[core]` Compute the average of an int array as a `double`. Watch the integer division.
34. `[core]` Bubble sort ascending, then change one comparison to sort descending.
35. `[core]` Linear search: report the index if found, and a clear "not found" message if the value is absent. A naive loop prints nothing when absent; fix that.
36. `[core]` Count how many times a given value appears in an array.
37. `[stretch]` Reverse an array in place using two indices moving toward each other.
38. `[stretch]` Remove duplicates from a sorted array in place and print the new length.
39. `[stretch]` 2D array: read a 3x3 matrix, print it, then print its transpose and the sum of the main diagonal.
40. `[stretch]` Merge two sorted arrays into a third sorted array without sorting again.

## 6. Searching and Sorting

41. `[core]` Binary search on a sorted array. Return the index, or -1 if absent.
42. `[core]` Add a guard to binary search that reports an error if the array is not sorted.
43. `[core]` Count the comparisons linear search vs binary search need on the same 1000-element array. Print both numbers.
44. `[stretch]` Selection sort and insertion sort. Which does fewer swaps, and why?
45. `[stretch]` Explain why `mid = (low + high) / 2` can overflow, and write the safe form.

## 7. Structures

46. `[warm]` Define `struct Student { string name; int age; double gpa; };`. Create one, fill it, print it.
47. `[core]` Array of 5 `Student`. Read them in, then print the one with the highest GPA.
48. `[core]` Write `void printStudent(Student s)` and `void printStudent(Student& s)`. Modify the struct inside each. Explain which change survives.
49. `[stretch]` Nested struct: `Address` inside `Student`. Print the full record.
50. `[stretch]` Sort an array of `Student` by GPA descending using bubble sort.

## 8. Pointers

51. `[warm]` Declare an int, print its value, its address, and the value via a pointer.
52. `[core]` Write a function that takes a pointer and modifies the caller's variable.
53. `[core]` Walk an array using pointer arithmetic instead of indices.
54. `[core]` Allocate an array with `new`, fill it, print it, then `delete[]` it.
55. `[stretch]` What is a dangling pointer? Write a snippet that creates one, then fix it.
56. `[stretch]` Explain the difference between `Node* p` and `Node*& p` as a parameter. Why do `insertStart` and `deleteBegining` need the reference?

## 9. Linked Lists

57. `[core]` Singly linked list: `createNode`, `insertEnd`, `traverse`, `countNodes`.
58. `[core]` `insertStart` and `insertAfter(target, value)`.
59. `[core]` `search(value)` returning the 1-based position, or -1.
60. `[core]` `deleteBeginning`, `deleteEnd`, `deleteByValue`. Handle: empty list, single node, value not present.
61. `[core]` `insertAtPosition(pos, value)`. Handle pos = 1, pos = last + 1, pos out of range, and an empty list. That last case is the one most people crash on.
62. `[core]` `deleteList` that frees every node and leaves head as `nullptr`.
63. `[stretch]` Reverse a singly linked list iteratively. Do not print inside the function.
64. `[stretch]` Find the middle node in one pass (slow pointer / fast pointer).
65. `[stretch]` Detect whether a list has a cycle.
66. `[stretch]` Doubly linked list: insert at end keeping both `next` and `prev` correct, then traverse forwards and backwards to prove it.
67. `[stretch]` Merge two sorted linked lists into one sorted list.

## 10. Input Robustness

68. `[core]` Take any program above that does `cin >> number`. Type `abc` instead. Watch it loop forever or silently use 0. Now fix it with `cin.fail()`, `cin.clear()` and `cin.ignore()`.
69. `[core]` Write a reusable `int readInt(string prompt)` that refuses to return until it gets a valid integer, and use it everywhere.
70. `[stretch]` Write `int readIntInRange(string prompt, int lo, int hi)`.

---

## Exam-style mixed set

**A.** Read 10 integers into an array. Print the sum, average, largest, smallest, and the array sorted ascending. No library sort.

**B.** Build a linked list of 8 values. Insert 99 after the 4th node. Delete the 2nd node. Reverse the list. Print the list and the node count after each step.

**C.** Menu-driven program that loops until the user picks "Exit", offering: add a number, list all numbers, find a number, delete a number, show the average.

**D.** Student record system: struct plus an array of 5, with functions to add, display all, find by name, and show the class average GPA.
