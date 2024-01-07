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