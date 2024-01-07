# Problem Description

This problem requires designing a `stack` class that implements the following functionalities:

**1. Basic Functionalities:**

- Constructor: Initializes a stack instance.
- Destructor: Cleans up resources, ensuring no memory leaks.

**2. Core Functionalities:**

- Push: Pushes an element onto the top of the stack.
- Pop: Pops the top element from the stack.
- Top: Gets the top element of the stack (outputs "null" if empty).
- Empty: Checks if the stack is empty.
- Size: Returns the size of the stack.


#### Input Description

The input contains multiple lines. The first line is a positive integer `N`, representing the number of subsequent command sequences.

The next `N` lines each contain a command in the format `[operation] [parameters]`.  The specific commands are:

**push command:**

- Format: `push [element]`
- Function: Pushes `element` onto the top of the stack.

**pop command:**

- Format: `pop`
- Function: Pops the top element from the stack.

**top command:**

- Format: `top`
- Function: Gets the top element of the stack. Outputs "null" if the stack is empty.

**empty command:**

- Format: `empty`
- Function: Checks if the stack is empty.

**size command:**

- Format: `size`
- Function: Returns the size of the stack.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

push command: No output.
pop command: No output.
top command: Outputs an integer on a new line, representing the top element.
empty command: Outputs "true" if empty, "false" otherwise, on a new line.
size command: Outputs an integer on a new line, representing the number of elements in the stack.


#### Input Example

```
14
push 1
push 2
push 3
size
empty
pop
pop
size
empty
top
pop
size
empty
top
```


#### Output Example

```
3
false
1
false
1
0
true
null
```


#### Hints

- Data range: 1 <= N <= 1000