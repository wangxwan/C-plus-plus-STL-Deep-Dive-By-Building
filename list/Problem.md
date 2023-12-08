## Problem Description

Design a class named `List` that has the following functionalities and characteristics:

1. **Basic Member Functions:**
   * Constructor: Initializes a `List` instance.
   * Destructor: Cleans up resources and ensures no memory leaks.

2. **Core Functionalities:**
   * Add an element to the end of the `List`.
   * Add an element to the beginning of the `List`.
   * Get the number of nodes in the `List`.
   * Remove the element at the end of the `List`.
   * Remove the element at the beginning of the `List`.
   * Remove a node with a specified value from the `List`.

3. **Iteration and Traversal:**
   * Print the elements in the linked list.

4. **Auxiliary Functions:**
   * Overload the `[]` operator for index-based access to the list.
   * Overload the `<<` operator to print the list.


## Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The next `N` lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:

* **`push_back` command:**
  * Format: `push_back [value]`
  * Function: Adds an element with the value `value` to the end of the linked list.

* **`push_front` command:**
  * Format: `push_front [value]`
  * Function: Adds an element with the value `value` to the beginning of the linked list.

* **`pop_back` command:**
  * Format: `pop_back`
  * Function: Removes the element at the end of the linked list.

* **`pop_front` command:**
  * Format: `pop_front`
  * Function: Removes the element at the beginning of the linked list.

* **`remove` command:**
  * Format: `remove [value]`
  * Function: Removes the element with the value `value` from the linked list.

* **`clear` command:**
  * Format: `clear`
  * Function: Clears the linked list.

* **`size` command:**
  * Format: `size`
  * Function: Gets the number of nodes in the linked list.

* **`get` command:**
  * Format: `get [index]`
  * Function: Gets the value of the node at index `index` in the linked list. If the index is invalid, output -1.

* **`print` command:**
  * Format: `print`
  * Function: Prints the elements in the linked list.


## Output Description

The output is the result after each command execution. The specific output format is as follows:

* `push_back`, `push_front`, `pop_back`, `pop_front`, `remove`, and `clear` commands: No output.
* `size` command: Outputs an integer on a single line, representing the current number of elements in the `List`.
* `get` command: Outputs an integer on a single line, representing the element at the specified index in the `List`. If the index is invalid, outputs -1.
* `print` command: Prints all elements in the current `List` in order, with a space after each element. The output is on a single line. If the `List` is empty, prints "empty".


## Input Example

```
17
push_back 10
push_back 20
push_front 30
push_front 40
size
print
get 1
pop_back
print
pop_front
print
remove 10
print
size
clear
print
size
```

## Output Example

```
4
40 30 10 20 
30
40 30 10 
30 10 
30 
1
empty
0
```

## Hint:

- Data range: 1 <= N <= 1000
