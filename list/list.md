# List

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


`std::list` and `std::vector` are two distinct data structures. `std::vector` is a dynamic array based on arrays, while `std::list` is a data structure based on a doubly linked list.

`list` is suitable for scenarios requiring frequent insertion and deletion operations within a sequence.

## Characteristics of `list`

- Doubly Linked List: `list` is a doubly linked list, allowing for efficient insertion and deletion operations at both ends and in the middle of the sequence.

- No Random Access: Unlike `vector` and `deque`, `list` does not support random access via index in constant time. To access elements in a `list`, iterators must be used.

- Dynamic Memory Management: The internal implementation of `list` uses nodes, each containing an element and pointers to the previous and next nodes. This structure allows `list` to better manage memory during insertion and deletion operations.

- Iterator Validity Preservation: `list` better preserves iterator validity during insertion and deletion operations. This means that these operations do not invalidate all iterators.

- Efficient Insertion and Deletion Operations: Because `list` is a doubly linked list, insertion and deletion operations are constant time at both ends and in the middle, making it an ideal container for handling such operations.

## Performance Considerations of `list`

Insertion and Deletion Operations: If frequent insertion and deletion operations are the primary focus, and random access to elements is not required, `list` might be more efficient than `vector` and `deque`.

Random Access: If random access to elements via index is needed, using `vector` might be more appropriate, as it provides constant-time random access.

Memory Usage: Because `list` uses a linked list structure, it might introduce some additional memory overhead.  `vector` and `deque` might be more memory-compact.

## Basic Usage of `list` in the C++ Standard Library

To use `list`, you first need to include the relevant header file:

```c++
#include <list>
```

Next, you can declare a `list` object and start using it:

```c++
std::list<int> myList;
```

You can insert elements at the front and back of the `list` using `push_front` and `push_back`:

```c++
myList.push_front(1);
myList.push_back(2);
```

Use `pop_front` and `pop_back` to remove elements from the front and back of the `list`:

```c++
myList.pop_front();
myList.pop_back();
```

## Implementing `list`

This example demonstrates the basic functionality of the `List` class, including adding elements to the end and beginning of the list, accessing elements, deleting elements from the end and beginning, and clearing the list.

[Detail](Implementation.md)


## High-Frequency Interview Questions

[Detail](Interview.md)

