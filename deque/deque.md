# deque

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


## Introduction

The `deque` (double-ended queue) in the C++ Standard Template Library (STL) is a data structure that stores elements in memory and supports adding and removing elements from both ends.

## Characteristics of `deque`

**Double-ended operations:** `deque` supports fast insertion and deletion operations at both the front and back ends, making it ideal for handling problems that require frequent operations at both ends.

**Random access:** Unlike `list`, `deque` allows random access to elements in constant time. This is because the internal structure of `deque` uses segmented arrays instead of linked lists, providing better random access performance.

**Dynamic resizing:** The size of a `deque` can be dynamically adjusted without needing to pre-allocate a fixed amount of memory. This makes `deque` suitable for situations where dynamic growth and shrinking are required.

**Iterator invalidation:** `deque` is designed to better maintain iterator validity during insertion and deletion operations. This means that these operations don't necessarily invalidate all iterators.

**Memory locality:** The internal structure of `deque`, utilizing multiple buffers, contributes to improved memory locality, potentially leading to better performance in certain scenarios.


For example, regarding random access:

In C++, `std::deque` allows random access to elements in constant time. This means elements in the `deque` can be accessed directly using their index without the access time increasing with the `deque`'s size.  [Here's a simple example.](characteristics.cpp)

In the above example, accessing `myDeque[2]` and `myDeque[4]` takes constant time, regardless of the `deque`'s size.

This is because `std::deque` uses a segmented array structure. Each segment is a fixed-size array, allowing direct calculation of the index location without traversing the entire container.

Note that while `std::deque` provides constant-time random access, it might involve more levels of indirection compared to `std::vector`.  Therefore, in some cases, `std::vector` might exhibit slightly better random access performance.

When choosing a container, the trade-offs between different containers should be considered based on the specific use case and requirements.


## Basic Usage of `deque` in the STL

To use `deque`, you first need to include the relevant header file:

```cpp
#include <deque>
```

Next, you can declare a `deque` object and start using it:

```cpp
std::deque<int> myDeque;
```

You can use `push_front` and `push_back` to insert elements at the front and back of the `deque`, respectively:

```cpp
myDeque.push_front(1);
myDeque.push_back(2);
```

Use `pop_front` and `pop_back` to remove elements from the front and back of the `deque`, respectively:

```cpp
myDeque.pop_front();
myDeque.pop_back();
```

## How `deque` Works

While the C++ STL `deque` specifies the interface and time complexity, it doesn't mandate a specific implementation. The C++ standard describes the behavior and performance requirements of each container, leaving the specific implementation to the implementer.  Here's a description of a possible implementation using a circular array:

This section describes a template class `Deque` that simulates a double-ended queue using a circular array.  Below is a summary of the implementation approach and the logic of each function.

#### Overall Approach

- **Data Structure:**
  - `elements`: A dynamic array to store queue elements.
  - `capacity`: The capacity of the array.
  - `size`: The number of elements currently in the array.
  - `frontIndex` and `backIndex`: Pointers to the front and back elements of the queue. Note that `frontIndex` and `backIndex` are similar to `begin` and `end` in the standard STL. `frontIndex` points to an existing element (except when the `deque` is empty), while `backIndex` points to the position after the last element, which is not yet occupied (if the capacity is full, it points to the `frontIndex` position).
- **Circular Array:** Uses the modulo operator to implement the circular effect of the array, allowing insertion and deletion at either end of the queue.  Index out-of-bounds are handled by the modulo operation, wrapping around to the other end of the array.
- **Dynamic Resizing:** When the array reaches its capacity limit, it automatically expands its capacity (doubles it), copying all existing elements to the new, larger array.
- **Index Calculation:** Uses the modulo operator to correctly calculate the new `frontIndex` and `backIndex` for both insertion and deletion operations.

#### Notes

- Both `push_front` and `push_back` check if the array is full. If full, the capacity is doubled, and the existing elements are copied to the new array.
- `push_front` decrements `frontIndex` before inserting at that position.  After decrementing, `frontIndex` is adjusted using the modulo operator with `capacity` to handle negative indices, effectively wrapping around to the end of the array.
- `push_back` inserts directly at `backIndex` and then increments `backIndex`.  The modulo operator with `capacity` is used to handle cases where `backIndex` exceeds the array bounds, wrapping it around to the beginning of the array.


(Note:  The actual implementation of a `Deque` class using a circular array would require significantly more code than what can be reasonably included in this response. This description provides a conceptual overview.)


## Implementing a Deque

This implementation uses a dynamic array and pointers to achieve basic deque operations.  Adding and removing elements from both the front and back of the deque are simulated using array indices.

[Detail](Implementation.md)

