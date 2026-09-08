Question 1 — Stack Using an Array

Implement a stack using an array in C++.

Your implementation should support the following operations:

1. push() — add an element to the stack.
2. pop() — remove the top element.
3. peek() — display the top element without removing it.
4. isEmpty() — determine whether the stack is empty.
5. isFull() — determine whether the stack is full.
6. display() — display all elements currently in the stack.

Requirements
1. Do not use the C++ Standard Template Library (#include <stack>).
2. Use a fixed-size array.
3. Handle stack overflow when attempting to push into a full stack.
4. Handle stack underflow when attempting to pop from an empty stack.
5. Test your implementation with at least 5 values.



Question 2 — Stack Using a Class

Rewrite your stack implementation from Question 1 using a C++ class.

Your class should contain:

Private members
An array for storing the elements.
A variable for keeping track of the top position.

Public methods
1. push()
2. pop()
3. peek()
4. isEmpty()
5. isFull()
6. display()

Requirements
1. Do not use std::stack.
2. Create a Stack object in main().
3. Demonstrate every operation.



Question 3 — Stack Using the C++ STL

Use the C++ Standard Template Library to create and manipulate a stack.

Use:

#include <stack>

Perform the following operations:

1. Create a stack of integers.
2. Push 10, 20, 30, 40, and 50.
3. Display the top element.
4. Remove the top two elements.
5. Display the new top element.
6. Display the number of elements remaining.
7. Determine whether the stack is empty.


Question 4 — Implement a Stack Without STL

Write a complete C++ program that implements a stack from scratch.

The program should provide a menu:

1. Push
2. Pop
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit

The user should be able to repeatedly select an operation until they choose to exit.

Restrictions
Do not use std::stack.
Use an array.
Use functions or a class.
Handle both overflow and underflow.