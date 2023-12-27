# Problem Description

This problem requires designing a `multiset` class that implements the following functionalities:


**1. Basic Functionalities**

- Constructor: Initializes a `multiset` instance.
- Destructor: Cleans up resources and ensures no memory leaks.


**2. Core Functionalities**

- Insert an element into the `multiset`.
- Delete elements from the `multiset`.
- Check if an element exists in the `multiset`.
- Check if the `multiset` is empty.
- Get the size of the `multiset`.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The following `N` lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:


**insert command:**

- Format: `insert [element]`
- Function: Adds `element` to the `multiset`. If the element already exists, no operation is performed.


**erase command:**

- Format: `erase [element]`
- Function: Deletes all occurrences of `element` from the `multiset`. If `element` does not exist, no operation is performed.


**count command:**

- Format: `count [element]`
- Function: Queries the number of occurrences of `element` in the `multiset`.


**empty command:**

- Format: `empty`
- Function: Checks if the `multiset` is empty.


**size command:**

- Format: `size`
- Function: Gets the number of elements in the `multiset`.


#### Output Description

The output is the result after each command execution, with the following specific output formats:


insert command: No output.

erase command: No output.

count command: Outputs an integer on a single line, representing the number of occurrences of the element in the `multiset`.

empty command: Outputs "true" if the `multiset` is empty, otherwise outputs "false".

size command: Outputs an integer on a single line, representing the total number of elements in the `multiset`.


#### Input Example

```
13
insert 1
insert 2
size
count 2
insert 2
size
count 2
erase 2
size
count 2
erase 1
size
empty
```


#### Output Example

```
2
1
3
2
1
0
0
true
```


#### Hints

- Data range: 1 <= N <= 1000