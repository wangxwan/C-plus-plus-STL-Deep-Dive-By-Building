# `priority_queue`

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


`priority_queue` is implemented using a heap data structure.

The C++ standard library uses `std::make_heap`, `std::push_heap`, and `std::pop_heap` to implement `priority_queue`.  

[This code demonstrates a custom implementation.](usage.cpp)

## How Heaps Work

A heap is a specialized complete binary tree that satisfies the following properties:

[Detail](principle.md)


## Differences from the C++ Standard Library

The STL's `std::priority_queue` defaults to using `std::vector` as its underlying container. This makes the code more flexible, allowing the choice of different container types.

The provided code does not use STL's heap algorithms like `std::make_heap`, `std::push_heap`, and `std::pop_heap` to maintain the heap property. Instead, it uses manually implemented heap operations, `heapifyUp` and `heapifyDown`.

The code uses custom exception handling for empty queue situations, while STL's `std::priority_queue` might throw a `std::out_of_range` exception.