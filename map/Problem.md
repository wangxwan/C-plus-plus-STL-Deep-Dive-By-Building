# Problem Description

This problem requires designing a `map` class that implements the following functionalities:

**1. Basic Functionalities:**

- **Constructor:** Initializes a `map` instance.
- **Destructor:** Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Insert an element into the map.
- Delete an element from the map.
- Check if an element exists in the map.
- Check if the map is empty.
- Get the size of the map.
- Get the value associated with a given key in the map.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The following `N` lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:

**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a key-value pair to the map. If the key already exists, no operation is performed.

**erase command:**

- Format: `erase [key]`
- Function: Deletes the key-value pair associated with the given key from the map. If the key does not exist, no operation is performed.

**contains command:**

- Format: `contains [key]`
- Function: Checks if a key exists in the map.

**empty command:**

- Format: `empty`
- Function: Checks if the map is empty.

**size command:**

- Format: `size`
- Function: Gets the size of the map.

**at command:**

- Format: `at [key]`
- Function: Retrieves the value associated with the given key in the map.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

`insert` command: No output.

`erase` command: No output.

`empty` command: Outputs "true" if the map is empty, otherwise "false". The output occupies a single line.

`size` command: Outputs an integer on a single line, representing the size of the map.

`at` command: If the key exists, outputs the value associated with the key; otherwise, outputs "not exist". The output occupies a single line.

`contains` command: Outputs "true" if the key exists, otherwise "false". The output occupies a single line.


#### Input Example

```
15
insert 1 1
insert 2 2
insert 3 3
size
contains 1
contains 4
erase 1
contains 1
at 2
at 4
empty
erase 2
erase 3
size
empty
```


#### Output Example

```
3
true
false
false
2
not exist
false
0
true
```


#### Hint

- Data range: 1 <= N <= 1000# Problem Description

This problem requires designing a `map` class that implements the following functionalities:

**1. Basic Functionalities:**

- **Constructor:** Initializes a `map` instance.
- **Destructor:** Cleans up resources and ensures no memory leaks.

**2. Core Functionalities:**

- Insert an element into the map.
- Delete an element from the map.
- Check if an element exists in the map.
- Check if the map is empty.
- Get the size of the map.
- Get the value associated with a given key in the map.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The following `N` lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:

**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a key-value pair to the map. If the key already exists, no operation is performed.

**erase command:**

- Format: `erase [key]`
- Function: Deletes the key-value pair associated with the given key from the map. If the key does not exist, no operation is performed.

**contains command:**

- Format: `contains [key]`
- Function: Checks if a key exists in the map.

**empty command:**

- Format: `empty`
- Function: Checks if the map is empty.

**size command:**

- Format: `size`
- Function: Gets the size of the map.

**at command:**

- Format: `at [key]`
- Function: Retrieves the value associated with the given key in the map.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

`insert` command: No output.

`erase` command: No output.

`empty` command: Outputs "true" if the map is empty, otherwise "false". The output occupies a single line.

`size` command: Outputs an integer on a single line, representing the size of the map.

`at` command: If the key exists, outputs the value associated with the key; otherwise, outputs "not exist". The output occupies a single line.

`contains` command: Outputs "true" if the key exists, otherwise "false". The output occupies a single line.


#### Input Example

```
15
insert 1 1
insert 2 2
insert 3 3
size
contains 1
contains 4
erase 1
contains 1
at 2
at 4
empty
erase 2
erase 3
size
empty
```


#### Output Example

```
3
true
false
false
2
not exist
false
0
true
```


#### Hint

- Data range: 1 <= N <= 1000