# Related Interview Questions

`std::vector` from the C++ Standard Template Library (STL) is a common topic in interviews because it's a fundamental container for representing dynamic arrays. Here are some common interview questions about `std::vector` and their answers:

1. **Describe the resizing process of `std::vector`.**

When elements are added to a `std::vector` and the current capacity is insufficient, the vector resizes. This typically involves the following steps:
    1. Allocate a larger memory block, usually twice the current size (this growth factor is implementation-dependent).
    2. Move all existing elements to the newly allocated memory.
    3. Destroy the old elements and release the old memory block.
    4. Insert the new element.
The copying and moving operations in this process can incur performance overhead, especially if the elements have complex copy constructors or move constructors.

2. **Explain the difference between `std::vector::push_back` and `std::vector::emplace_back`.**

Both `std::vector::push_back` and `std::vector::emplace_back` add a new element to the end of the `std::vector`, but they differ in how they add the element.

- `push_back` copy-constructs or move-constructs the given object to add it to the end of the vector.
- `emplace_back` constructs the element in place at the end of the vector using the provided arguments, avoiding copy or move operations, which is generally more efficient.

3. **When would you use `std::vector::reserve()`?**

`std::vector::reserve()` is used to preallocate memory to avoid reallocations when adding new elements.  Use `reserve()` when you know you're going to store a large number of elements but don't want potential reallocations on every insertion. This can improve performance by reducing unnecessary memory allocations and element copying due to resizing.

4. **How can you reduce the space occupied by a `std::vector`?**

You can use the `std::vector::shrink_to_fit` method to request the removal of unused capacity, reducing the vector's memory usage. This function, introduced in C++11, attempts to reduce the capacity of the `std::vector` to match its size. However, this is only a request and is not guaranteed to reduce the capacity, as it depends on the implementation.

5. **How do you check if a `std::vector` is empty?**

Use the `std::vector::empty()` method to check if the vector has no elements. This is preferred over using the `size()` method (comparing `size() == 0`) because `empty()` is usually guaranteed to be a constant-time operation.

6. **What is iterator invalidation? How can it be avoided?**

Iterators can become invalid when the vector is modified, such as adding or removing elements, especially inserting or deleting elements in the middle. For example:

- If the vector is reallocated, all iterators pointing to elements become invalid.
- If elements are inserted or deleted in the middle of the vector, all iterators from that point to the end become invalid.
  The solution is to preferably use standard library algorithms like `std::remove` and `std::remove_if` in conjunction with `vector::erase` to remove elements. These algorithms are designed to handle iterator invalidation.

7. **What are the considerations when elements of a `std::vector` are pointers?**

When the elements of a `std::vector` are pointers, consider the following:
    1. **Memory Management:** If the `std::vector` stores raw pointers, simply clearing the vector or letting it be destroyed will not release the memory pointed to by the pointers.  You need to ensure that all dynamically allocated objects are deleted individually before the vector is destroyed.
    2. **Ownership and Lifetime:** Ensure that the objects pointed to by the pointers contained in the vector are valid during their use.  Clearly define who owns these objects and where and when they are released.
    3. **Exception Safety:** If an exception occurs during the creation and population of the vector, have a clear mechanism to handle already allocated memory to prevent memory leaks.
    4. **Smart Pointers:** To simplify memory management, it's recommended to use smart pointers (like `std::unique_ptr` or `std::shared_ptr`) as the element type of the vector. This way, when the vector is cleared or destroyed, the smart pointers automatically release the resources they own.
    5. **Avoiding Dangling Pointers:** When the object pointed to by a pointer is deleted or moved, ensure that there are no dangling pointers pointing to invalid memory addresses. Similarly, when the vector is reallocated, if it stores pointers to other elements, these pointers will become invalid.
    6. **Deep Copy vs. Shallow Copy:** If you need to copy such a vector, you need to decide whether to perform a deep copy (copying the objects pointed to by the pointers) or a shallow copy (copying only the pointers themselves). The correct choice depends on the application requirements and ownership strategy.

