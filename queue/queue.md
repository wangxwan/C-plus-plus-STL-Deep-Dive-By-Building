# Queue

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


`std::queue` is a container adapter in the C++ Standard Template Library (STL) that provides queue functionality (FIFO, First-In, First-Out).

A queue is a First-In, First-Out (FIFO) data structure, meaning the element that was added first will be the first one removed.  Think of a line at a ticket counter; the first person in line is the first person served and leaves the line.

## Features

- **First-In, First-Out (FIFO):**  Similar to a real-world queue, elements in `std::queue` are arranged in a sequential order, with the first element added being the first element removed.
- **Encapsulation:** `std::queue` provides encapsulation over an underlying container. By default, `std::queue` uses `std::deque` as its underlying container, but it can be configured to use `std::list` or other suitable containers.
- **Simple Interface:** `std::queue` offers a simple interface for adding, removing, and accessing the front and back elements of the queue.

## Performance

**Time Complexity:** Enqueue (push) and dequeue (pop) operations are typically constant time O(1), meaning the time taken for these operations doesn't significantly increase with the size of the queue.

**Space Complexity:** Since `std::queue` uses an underlying container to store elements, its space complexity depends on the underlying container used.

For example, when using `std::deque`, the space complexity is generally linear O(n), where n is the number of elements in the queue.


## Basic Usage in the C++ Standard Library

[This code demonstrates basic usage.](usage.cpp)


## Hands-on Implementation

[Detail](Implementation.md)


## Differences from the Standard Library

Compared to `std::queue` in the C++ Standard Template Library (STL), the provided `MyQueue` implementation has the following differences:

**Underlying Container Selection:** This code allows users to choose different underlying containers (e.g., `std::deque`, `std::list`, or `std::vector`) when instantiating a `MyQueue` object.  The C++ STL `std::queue` defaults to `std::deque` and doesn't offer the option to directly select a different container.

**Exception Handling:** This code adds error handling when popping and accessing the front element of the queue, using exceptions to handle the empty queue case.  The C++ STL `std::queue` typically doesn't provide similar error handling; users must handle the empty queue case themselves.

**Functionality Completeness:** The C++ STL `std::queue` is a complete container adapter providing additional functionalities such as `emplace`, `swap`, etc., while this code only provides basic queue operations.

**Iterators and Member Functions:** The C++ STL `std::queue` provides specific member functions and iterators, allowing for more flexible queue manipulation. This code only provides basic queue operation functions.


## Common Interview Questions

Interview questions about queues often cover fundamental concepts, data structure design, algorithms, and application scenarios. Here are some frequently asked questions and their answers.

[Detail](Interview.md)