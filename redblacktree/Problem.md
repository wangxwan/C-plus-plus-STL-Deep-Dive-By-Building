# Problem Description

In STL, the red-black tree is an important underlying data structure. This problem requires designing a `RedBlackTree` class to implement the following functionalities:

**1. Basic Functionalities**

- Constructor: Initializes a `RedBlackTree` instance.
- Destructor: Cleans up resources and ensures no memory leaks.


**2. Core Functionalities**

- Insert a node into the `RedBlackTree`.
- Delete a node from the `RedBlackTree`.
- Check if a node with a given key exists in the `RedBlackTree`.
- Get the number of nodes in the `RedBlackTree`.
- Get all nodes in the `RedBlackTree`.

Nodes in the `RedBlackTree` have two attributes: a `key` and a `value`.  The problem statement specifies that if the keys are the same, they represent the same node.


#### Input Description

The input contains multiple lines. The first line is a positive integer `N`, representing the number of subsequent command sequences.

The next `N` lines each contain a command in the format `[operation] [parameters]`.  The specific commands are as follows:


**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a node to the `RedBlackTree`. If the node already exists, no operation is performed.

**remove command:**

- Format: `remove [key]`
- Function: Deletes a node from the `RedBlackTree`. If the node does not exist, no operation is performed.

**at command:**

- Format: `at [key]`
- Function: Queries a node in the `RedBlackTree`.

**size command:**

- Format: `size`
- Function: Gets the number of nodes in the `RedBlackTree`.

**print command:**

- Format: `print`
- Function: Outputs all nodes in the `RedBlackTree` in inorder traversal, in the format `[key1] [value1] [key2] [value2]...`.


#### Output Description

The output is the result after each command execution. The specific output format is as follows:


insert command: No output.

remove command: No output.

at command: Outputs an integer on a single line, representing the `value` corresponding to the `key` in the `RedBlackTree`. If the `key` does not exist, it outputs "not exist".

size command: Outputs an integer on a single line, representing the number of nodes in the `RedBlackTree`.

print command: Outputs the keys and values of all nodes in the `RedBlackTree` in inorder traversal, in the format `[key1] [value1] [key2] [value2]...`. Each number is followed by a space. The output occupies a single line. If the `RedBlackTree` does not contain any nodes, it outputs "empty".


#### Input Example

```
11
insert 1 1
insert 2 2
insert 3 3
size
print
at 1
at 2
at 4
remove 1
print
size
```


#### Output Example

```
3
1 1 2 2 3 3 
1
2
not exist
2 2 3 3 
2
```


#### Hint

- Data range: 1 <= N <= 1000