# Problem Description

This problem requires designing an `unordered_map` class with the following functionalities:



**1. Basic Functionalities:**

- Constructor: Initializes an `unordered_map` instance.
- Destructor: Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Insert an element into the `unordered_map`.
- Delete an element from the `unordered_map`.
- Check if an element exists in the `unordered_map`.
- Check if the `unordered_map` is empty.
- Get the size of the `unordered_map`.



#### Input Description

The input contains multiple lines. The first line is a positive integer N, representing the number of subsequent command lines.

The following N lines each contain a command in the format [operation] [parameters].  The specific commands are as follows:



**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a key-value pair to the map. If the key already exists, no operation is performed.

**erase command:**

- Format: `erase [key]`
- Function: Deletes the key-value pair corresponding to the key from the `unordered_map`. If the key does not exist, no operation is performed.

**find command:**

- Format: `find [key]`
- Function: Checks if the `unordered_map` contains a key-value pair with the given key.

**empty command:**

- Format: `empty`
- Function: Checks if the `unordered_map` is empty.

**size command:**

- Format: `size`
- Function: Gets the size of the `unordered_map`.



#### Output Description

The output is the result of each command execution, with the following specific output formats:

insert command: No output.

erase command: No output.

empty command: If the `unordered_map` is empty, output `true`; otherwise, output `false`. The output occupies a single line.

size command: Output an integer on a single line, representing the size of the `unordered_map`.

find command: If the key exists, output `true`; otherwise, output `false`. The output occupies a single line.



#### Input Example

```
15
insert 1 1
insert 2 2
insert 3 3
find 1
find 2
find 4
size
empty
erase 1
find 1
size
erase 2
erase 3
size
empty
```



#### Output Example

```
true
true
false
3
false
false
2
0
true
```



#### Hints

- Data range: 1 <= N <= 1000