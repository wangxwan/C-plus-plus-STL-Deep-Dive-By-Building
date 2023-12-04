# Vector

`std::vector` is a dynamic array that stores elements in a contiguous block of memory. Unlike static arrays, `std::vector` allows dynamic resizing at runtime without manual memory management.

## Memory Management

`std::vector` maintains two important pieces of state information: capacity and size. Capacity represents the currently allocated memory space of the vector, while size represents the number of elements currently contained in the vector. When elements are added to the vector, if the number of elements exceeds the capacity, memory reallocation is required.

[Detail](MemoryManagement.md)

## Basic Usage of vector

It is located in the `<vector>` header file, which needs to be included when using it:

```c++
#include <vector>
```

[Creation, Initialization, and Element Access](basic.cpp)

## How vector Works

The array memory of a `vector` in `C++` is typically allocated on the heap. When a `vector` object is created, the object itself (i.e., the `vector`'s control structure, including pointers to the data, size, and capacity) is usually stored on the stack (if it's a local variable) or in other storage areas (such as global/static storage), but the actual element data is allocated on the heap.

This design allows the `vector` to grow and shrink dynamically at runtime, as the heap is the area used for dynamic memory allocation and has no fixed size limit (except for the physical limitations of available memory). When methods like `push_back` are called, the `vector` may reallocate its underlying dynamic array to accommodate new elements. This typically involves allocating a new, larger memory block, copying existing elements to the new memory, adding the new element, and then releasing the old memory block. In the official `C++` implementation of `vector`, this dynamic memory management is usually done through an allocator. The `vector` uses a default allocator, `std::allocator`, which encapsulates dynamic memory allocation functions like `new` and `delete`. Developers can also provide custom allocators for the `vector` to accommodate specific memory allocation strategies.

## Implementing vector

The Vector class includes a constructor, destructor, copy constructor, copy assignment operator, functions for adding elements, getting the number of elements, getting the capacity, and accessing elements.

[Detail](Implementation.md)

