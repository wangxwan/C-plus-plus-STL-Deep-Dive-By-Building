# Problem Description

This problem requires designing an `unordered_set` class that implements the following functionalities:

**1. Basic Functionalities:**

- **Constructor:** Initializes an `unordered_set` instance.
- **Destructor:** Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Insert an element into the `unordered_set`.
- Delete an element from the `unordered_set`.
- Check if an element exists in the `unordered_set`.
- Check if the `unordered_set` is empty.
- Get the size of the `unordered_set`.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The following `N` lines each contain a command in the format `[operation] [parameters]`.  The specific commands are:

**`insert` command:**

- Format: `insert [element]`
- Function: Adds an element to the `unordered_set`. If the element already exists, no operation is performed.

**`erase` command:**

- Format: `erase [element]`
- Function: Deletes an element from the `unordered_set`. If the element does not exist, no operation is performed.

**`find` command:**

- Format: `find [element]`
- Function: Queries for the existence of an element in the `unordered_set`.

**`empty` command:**

- Format: `empty`
- Function: Checks if the unordered set is empty.

**`size` command:**

- Format: `size`
- Function: Gets the size of the unordered set.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

- `insert` command: No output.
- `erase` command: No output.
- `find` command: Outputs `true` if the element exists, otherwise `false`.
- `empty` command: Outputs `true` if the `unordered_set` is empty, otherwise `false`.
- `size` command: Outputs the size of the `unordered_set`.


#### Input Example

```
13
insert 1
insert 2
insert 3
find 1
find 4
size
erase 1
erase 2
empty
size
erase 3
empty
size
```


#### Output Example

```
true
false
3
false
1
true
0
```


#### Hints

- Data range: 1 <= N <= 1000

