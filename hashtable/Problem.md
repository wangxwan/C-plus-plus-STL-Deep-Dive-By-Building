# Problem Description

In the STL, the HashTable is an important underlying data structure. This problem requires designing a HashTable and implementing the following functionalities:

**1. Basic Functionalities**

- Constructor: Initializes a HashTable instance.
- Destructor: Cleans up resources and ensures no memory leaks.

**2. Core Functionalities**

- Add a key-value pair to the HashTable.
- Delete a key-value pair from the HashTable.
- Query a key-value pair in the HashTable.
- Get the number of key-value pairs in the HashTable.
- Get all key-value pairs in the HashTable.

**3. Advanced Functionalities**

- Implement automatic resizing when the number of key-value pairs reaches a certain threshold.


#### Input Description

The input contains multiple lines. The first line is a positive integer N, representing the number of subsequent command sequences.

The next N lines each contain a command in the format `[operation] [parameters]`.  The specific commands are as follows:

**insert command:**

- Format: `insert [key] [value]`
- Function: Adds a key-value pair to the HashTable. If the key already exists, no operation is performed.

**erase command:**

- Format: `erase [key]`
- Function: Deletes a key-value pair from the HashTable. If the key does not exist, no operation is performed.

**find command:**

- Format: `find [key]`
- Function: Queries a key-value pair in the HashTable.

**size command:**

- Format: `size`
- Function: Outputs the number of key-value pairs in the HashTable.

**print command:**

- Format: `print`
- Function: Outputs all key-value pairs in the HashTable.

**clear command:**

- Format: `clear`
- Function: Clears the hash table.


#### Output Description

The output is the result after each command execution. The specific output format is as follows:

insert command: No output.
erase command: No output.
find command: Outputs an integer on a separate line, representing the value corresponding to the key. If the key does not exist in the HashTable, outputs "not exist".
size command: Outputs an integer on a separate line, representing the number of key-value pairs in the HashTable.
print command: Prints all key-value pairs in the HashTable in the format `[key1] [value1] [key2] [value2]...` Each number is followed by a space. The output is on a separate line. If the HashTable is empty, prints "empty".
clear command: No output.


#### Input Example

```
14
insert 1 2
insert 3 4
insert 5 6
size
print
find 1
find 2
erase 1
find 1
size
print
clear
print
size
```


#### Output Example

```
3
1 2 3 4 5 6 
2
not exist
2
3 4 5 6 
empty
0
```


#### Hints

- Data range: 1 <= N <= 1000