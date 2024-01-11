# Problem Description

This problem requires designing a `priority_queue` class that implements the following functionalities:


**1. Basic Functionalities**

- Constructor: Initializes a `priority_queue` instance.
- Destructor: Cleans up resources and ensures no memory leaks.


**2. Core Functionalities**

- Add an element to the `priority_queue`.
- Pop the maximum element from the `priority_queue`.
- Get the maximum element from the `priority_queue`.
- Get the number of elements in the `priority_queue`.
- Check if the `priority_queue` is empty.


#### Input Description

The input contains multiple lines. The first line contains a positive integer N, representing the number of subsequent command sequences.

The next N lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:


**push command:**

- Format: `push [element]`
- Function: Adds `element` to the `priority_queue`.

**pop command:**

- Format: `pop`
- Function: Pops the maximum element from the `priority_queue`.

**top command:**

- Format: `top`
- Function: Accesses the maximum element in the `priority_queue`.

**empty command:**

- Format: `empty`
- Function: Checks if the `priority_queue` is empty.

**size command:**

- Format: `size`
- Function: Returns the size of the `priority_queue`.


#### Output Description

The output is the result after each command execution. The specific output format is as follows:

push command: No output.

pop command: No output.

top command: Outputs an integer on a single line, representing the largest element in the `priority_queue`. If the `priority_queue` is empty, outputs "null".

empty command: Outputs "true" if empty, "false" otherwise, on a single line.

size command: Outputs an integer on a single line, representing the size of the `priority_queue`.


#### Input Example

```
18
push 10
push 20
push 30
push 40
top
size
pop
top
size
empty
pop
pop
top
size
pop
empty
pop
top
```


#### Output Example

```
40
4
30
3
false
10
1
true
null
```


#### Hints

- Data range: 1 <= N <= 1000