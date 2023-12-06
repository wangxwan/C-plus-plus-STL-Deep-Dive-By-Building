## Problem Description

Design a Vector class named MyVector with the following functionalities and features:

1. **Basic Member Functions:**
    * Constructor: Initializes a MyVector instance.
    * Destructor: Cleans up resources and ensures no memory leaks.
    * Copy Constructor: Allows creating a new instance from an existing MyVector instance.
    * Copy Assignment Operator: Implements assignment functionality between MyVector instances.

2. **Core Functionality:**
    * Append Element: Adds a new element to the end of the Vector.
    * Get Element Count: Returns the current number of elements in the Vector.
    * Get Capacity: Returns the total number of elements the Vector can hold.
    * Access Element at Index: Accesses the element at a specific index.
    * Insert Element at Index: Inserts a new element at a specific index in the Vector.
    * Remove Last Element: Removes the element at the end of the Vector.
    * Clear: Removes all elements from the Vector and resets its state.

3. **Iteration and Traversal:**
    * Iterate Using Iterators: Implements iterators to support traversing the Vector from beginning to end.
    * Print Elements: Provides a function to traverse and print all elements using iterators.

4. **Advanced Features:**
    * Dynamic Resizing: Automatically expands the Vector's capacity to store more elements when the current capacity is insufficient.

## Input Description

The input consists of multiple lines. The first line contains a positive integer N, representing the number of command sequences that follow.
The next N lines each contain a command in the format [operation] [parameters]. The specific commands are as follows:

* **push command:**
    * Format: push [element]
    * Function: Adds the element to the end of the Vector.
* **size command:**
    * Format: size
    * Function: Returns the current number of elements in the Vector.
* **get command:**
    * Format: get [index]
    * Function: Returns the element at the specified index.
* **insert command:**
    * Format: insert [index] [element]
    * Function: Inserts an element at the specified index in the Vector.
* **pop command:**
    * Format: pop
    * Function: Removes the last element from the Vector.
* **clear command:**
    * Format: clear
    * Function: Removes all elements from the Vector and resets its state.
* **print command:**
    * Format: print
    * Function: Prints all elements in the Vector.
* **iterator command:**
    * Format: iterator
    * Function: Demonstrates iterator usage by printing all elements.
* **foreach command:**
    * Format: foreach
    * Function: Prints all elements using a loop.

## Output Description

The output contains N lines. Different commands require specific feedback. The output format is as follows:

* **push command:** No output.
* **size command:** Outputs an integer on a separate line, representing the current number of elements in the vector.
* **get command:** Outputs an integer on a separate line. If the index is valid, outputs the element at the specified index. If the index is invalid, outputs -1.
* **insert command:** No output.
* **pop command:** No output.
* **clear command:** No output.
* **print command:** Prints all elements in the current vector, each followed by a space, on a separate line. If the vector is empty, prints "empty".
* **iterator command:** Prints all elements in the current vector, each followed by a space, on a separate line. If the vector is empty, prints "empty".
* **foreach command:** Prints all elements in the current vector, each followed by a space, on a separate line. If the vector is empty, prints "empty".

## Input Example

> 15
push 20
push 30
push 40
print
insert 0 10
size
print
get 1
pop
print
iterator
foreach
clear
size
print

## Output Example

> 20 30 40 
4
10 20 30 40 
20
10 20 30 
10 20 30 
10 20 30 
0
empty

## Hints

- Data Range: 1 <= N <= 1000
