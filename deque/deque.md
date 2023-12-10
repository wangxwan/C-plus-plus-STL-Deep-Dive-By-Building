# deque

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
