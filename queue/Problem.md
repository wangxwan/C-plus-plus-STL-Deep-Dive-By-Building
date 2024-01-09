# Problem Description

This problem requires designing a `queue` class that implements the following functionalities:

**1. Basic Functionalities**

- Constructor: Initializes a `queue` instance.
- Destructor: Cleans up resources and ensures no memory leaks.

**2. Core Functionalities**

- Add an element to the rear of the queue.
- Remove the element at the front of the queue.
- Access the element at the front of the queue.
- Access the element at the back of the queue.
- Get the size of the queue.
- Check if the queue is empty.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The next `N` lines each contain a command. The command format is `[operation] [parameters]`, with the following specific commands:

**push command:**

- Format: `push [element]`
- Function: Adds `element` to the rear of the queue.

**pop command:**

- Format: `pop`
- Function: Removes the element at the front of the queue.

**front command:**

- Format: `front`
- Function: Gets the element at the front of the queue. Outputs "null" if the queue is empty.

**back command:**

- Format: `back`
- Function: Gets the element at the back of the queue. Outputs "null" if the queue is empty.

**empty command:**

- Format: `empty`
- Function: Checks if the queue is empty.

**size command:**

- Format: `size`
- Function: Returns the size of the queue.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

`push` command: No output.
`pop` command: No output.
`front` command: Outputs an integer on a single line, representing the front element.
`back` command: Outputs an integer on a single line, representing the back element.
`empty` command: Outputs "true" if empty, "false" otherwise, on a single line.
`size` command: Outputs an integer on a single line, representing the size of the queue.


#### Input Example

```
14
push 1
push 2
push 3
size
front
back
pop
front
size
empty
pop
pop
size
empty
```


#### Output Example

```
3
1
3
2
2
false
0
true
```


#### Hints

- Data range: 1 <= N <= 1000