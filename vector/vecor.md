# Vector

`std::vector` is a dynamic array that stores elements in a contiguous block of memory. Unlike static arrays, `std::vector` allows dynamic resizing at runtime without manual memory management.

## Memory Management

`std::vector` maintains two important pieces of state information: capacity and size. Capacity represents the currently allocated memory space of the vector, while size represents the number of elements currently contained in the vector. When elements are added to the vector, if the number of elements exceeds the capacity, memory reallocation is required.

[Detail](MemoryManagement.md)