# Stack

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


In the C++ Standard Template Library (STL), a stack is implemented as a container adapter.  This provides a simplified interface, allowing developers to easily utilize the stack data structure.

## Features

1. **Container-Based:** The `std::stack` in the C++ STL is a container adapter; it's not a standalone data structure but is built on top of other containers. By default, `std::stack` uses `std::deque` as its underlying container, but other containers like `std::vector` and `std::list` can also be specified.

```cpp
std::stack<int, std::deque<int>> stack1;  // Uses std::deque as the underlying container
std::stack<int, std::vector<int>> stack2; // Uses std::vector as the underlying container
```

2. **Basic Operations:** `std::stack` provides common stack operations, including:

* `push(val)`: Pushes an element onto the top of the stack.
* `pop()`: Pops the top element from the stack.
* `top()`: Accesses the top element of the stack.
* `empty()`: Checks if the stack is empty.
* `size()`: Returns the size of the stack.

```cpp
std::stack<int> stack;
stack.push(1);
stack.push(2);
int topElement = stack.top(); // Accesses the top element
stack.pop();
bool isEmpty = stack.empty();
size_t stackSize = stack.size();
```

## Performance

The performance of `std::stack` is largely dependent on the performance characteristics of its underlying container.  By default, using `std::deque` provides good performance for most operations. However, choosing a different underlying container can impact performance in certain scenarios.

* **Using `std::vector` as the underlying container:** Offers fast random access but can be less efficient for inserting and deleting elements.
* **Using `std::list` as the underlying container:** Offers fast insertion and deletion but slower random access.

Therefore, choosing the underlying container requires a trade-off based on specific operational needs and performance considerations.


## Hands-on Implementation

The following example demonstrates how to implement a stack using C++ standard library containers (e.g., `std::deque`), providing basic stack operations. Note that the actual `std::stack` implementation is more complex and robust.

[Detail](Implementation.md)


## Differences from the Standard Library

This `MyStack` implementation differs from `std::stack` in the C++ STL in several key aspects:

* **Underlying Container Selection:** This code allows users to choose different underlying containers (e.g., `std::deque` or `std::list`) when instantiating a `MyStack` object.  In contrast, `std::stack` in the C++ STL defaults to `std::deque` and doesn't offer a direct option to select a different container.

* **Flexibility:** This code is more flexible, allowing the selection of different underlying container types based on specific needs, making the stack implementation more general-purpose and customizable.

* **Error Handling:** This code incorporates error handling when popping and accessing the top element, using exceptions to handle the case of an empty stack.  `std::stack` in the C++ STL typically doesn't provide similar error handling; users must handle empty stack conditions themselves.

* **Feature Completeness:** `std::stack` in the C++ STL is a full container adapter, providing additional functionalities such as `emplace`, `swap`, etc., while this code only provides basic stack operations.

* **Iterators and Member Functions:** `std::stack` in the C++ STL offers specific member functions and iterators, allowing for more flexible stack manipulation, whereas this code only provides basic stack operation functions.


## Common Interview Questions

[Detail](Interview.md)