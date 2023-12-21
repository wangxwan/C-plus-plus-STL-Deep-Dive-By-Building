# Problem Description

This problem requires designing a `Set` class that implements the following functionalities:

**1. Basic Functionalities**

- **Constructor:** Initializes a `Set` instance.
- **Destructor:** Cleans up resources and ensures no memory leaks.

**2. Core Functionalities**

- Insert an element into the `Set`.
- Delete an element from the `Set`.
- Check if an element exists in the `Set`.
- Check if the `Set` is empty.
- Get the size of the `Set`.


#### Input Description

The input consists of multiple lines. The first line contains a positive integer `N`, representing the number of subsequent command sequences.

The following `N` lines each contain a command in the format `[operation] [parameters]`.  The specific commands are as follows:


**insert command:**

- **Format:** `insert [element]`
- **Functionality:** Adds `element` to the `Set`. If the element already exists, no operation is performed.

**erase command:**

- **Format:** `erase [element]`
- **Functionality:** Deletes `element` from the `Set`. If `element` does not exist in the set, no operation is performed.

**contains command:**

- **Format:** `contains [element]`
- **Functionality:** Checks if the `Set` contains the `element`.

**empty command:**

- **Format:** `empty`
- **Functionality:** Checks if the `Set` is empty.

**size command:**

- **Format:** `size`
- **Functionality:** Gets the size of the `Set`.


#### Output Description

The output is the result of each command execution, with the following specific output formats:

- **insert command:** No output.
- **erase command:** No output.
- **contains command:** Outputs `true` if the `Set` contains the element, otherwise `false`. The output occupies a single line.
- **empty command:** Outputs `true` if the `Set` is empty, otherwise `false`. The output occupies a single line.
- **size command:** Outputs an integer on a single line, representing the size of the `Set`.


#### Input Example

```
13
insert 1
insert 2
insert 3
contains 1
contains 4
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