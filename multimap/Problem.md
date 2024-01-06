# Problem Description

This problem requires designing a `multimap` class with the following functionalities:

**1. Basic Functionalities:**

- Constructor: Initializes a `multimap` instance.
- Destructor: Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Insert an element into the `multimap`.
- Remove a specific key-value pair from the `multimap`.
- Remove all values associated with a specific key from the `multimap`.
- Check if the `multimap` is empty.
- Get the size of the `multimap`.
- Iterate and print the values associated with each key in the `multimap`.
- Get the values associated with a specific key in the `multimap`.


#### Input Description

The input contains multiple lines. The first line is a positive integer N, representing the number of subsequent command lines.

The following N lines each contain a command in the format `[operation] [parameters]`.  The specific commands are as follows:

**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a key-value pair to the map. If the key already exists, no operation is performed.

**remove command:**

- Format: `remove [key] [value]`
- Function: Removes the specified value associated with the given key from the map.

**remove_all command:**

- Format: `remove_all [key]`
- Function: Removes all values associated with the given key from the map.

**at command:**

- Format: `at [key]`
- Function: Retrieves the values associated with the given key.

**empty command:**

- Format: `empty`
- Function: Checks if the `multimap` is empty.

**size command:**

- Format: `size`
- Function: Gets the size of the `multimap`.


#### Output Description

The output shows the result of each command execution. The specific output format is as follows:

insert command: No output.

remove command: No output.

remove_all command: No output.

empty command: Outputs "true" if the `multimap` is empty, otherwise "false". The output occupies a single line.

size command: Outputs an integer representing the size of the `multimap` on a single line.

at command: Retrieves the values associated with the given key. If multiple values exist, prints all values separated by spaces. If the key does not exist, outputs "not exist". The output occupies a single line.


#### Input Example

```
19
insert 1 1
insert 1 2
insert 1 3
insert 2 1
insert 3 1
at 1
at 2
size
empty
remove 1 3
at 1
remove 2 1
at 2
size
empty
remove_all 1
remove_all 3
size
empty
```



#### Output Example

```
1 2 3 
1
5
false
1 2 
not exist
3
false
0
true
```



#### Hints

- Data range: 1 <= N <= 1000