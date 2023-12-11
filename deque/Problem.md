# Problem Description

Design a `Deque` class that implements a double-ended queue with the following functionalities and characteristics:

**1. Basic Member Functions:**

- Constructor: Initializes a `Deque` instance.
- Destructor: Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Add an element to the end of the `Deque`.
- Add an element to the beginning of the `Deque`.
- Remove the element from the end of the `Deque`.
- Remove the element from the beginning of the `Deque`.
- Get the number of nodes in the `Deque`.
- Remove all elements from the `Deque`.

**3. Iteration and Traversal:**

- Print the elements in the `Deque`.

**4. Auxiliary Functionalities:**

- Overload the `[]` operator for index-based access to the `Deque`.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command lines.

The following `N` lines each contain a command in the format `[operation] [parameters]`.  The specific commands are as follows:

**`push_back` command:**

- Format: `push_back [value]`
- Function: Adds an element with the value `value` to the end of the deque.

**`push_front` command:**

- Format: `push_front [value]`
- Function: Adds an element with the value `value` to the beginning of the deque.

**`pop_back` command:**

- Format: `pop_back`
- Function: Removes the element from the end of the deque.

**`pop_front` command:**

- Format: `pop_front`
- Function: Removes the element from the beginning of the deque.

**`clear` command:**

- Format: `clear`
- Function: Clears the deque.

**`size` command:**

- Format: `size`
- Function: Gets the number of nodes in the deque.

**`get` command:**

- Format: `get [index]`
- Function: Gets the value of the node at index `index` in the deque.

**`print` command:**

- Format: `print`
- Function: Prints the elements in the deque.


#### Output Description

The output shows the result after each command execution. The specific output format is as follows:

`push_back`, `push_front`, `pop_back`, `pop_front`, and `clear` commands: No output.

`size` command: Outputs an integer on a single line, representing the number of elements in the `Deque`.

`get` command: Outputs the value of the node at the specified index.

`print` command: Prints the elements of the `Deque`.


#### Input Example

```
15
push_back 20
push_back 10
push_front 30
push_front 40
size
print
pop_back
print
pop_front
print
size
get 1
clear
print
size
```

#### Output Example

```
4
40 30 20 10 
40 30 20 
30 20 
2
20
empty
0
```

#### Constraints

```
1 <= N <= 1000
```
