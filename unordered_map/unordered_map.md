# `unordered_map`

[Problem Description](Problem.md)

[Solution](Solution.cpp)


`std::unordered_map`, part of the C++ Standard Template Library (STL), is an associative container implemented using a hash table.  This allows for fast access to key-value pairs with an average time complexity of O(1).  `unordered_map` is widely popular for its efficient performance and flexible usage.

## Characteristics of `unordered_map`

1. **Key-Value Pair Storage:** `unordered_map` stores elements as key-value pairs, where each key is unique and maps to a single value. This enables fast retrieval of values using their keys.

2. **Hash Table Implementation:**  It's implemented using a hash table.  A hash function converts keys into indices used to locate the value's position within an internal array.

3. **Unordered:** Unlike `std::map`, elements in `unordered_map` are unordered.  The order depends on the hash function and the insertion order, not the key values.

4. **Customizable Hash and Equality Functions:** Users can provide custom hash functions and key equality comparison functions to accommodate specific needs.


## Performance of `unordered_map`

1. **Access Performance:** Ideally, element access (insertion, deletion, lookup) has a time complexity of O(1). However, hash collisions can degrade performance to O(n), where n is the number of elements in the same hash bucket.

2. **Collision Resolution:** `unordered_map` resolves hash collisions using linked lists (or other data structures, depending on the implementation). When multiple elements map to the same bucket, they are stored in a linked list.

3. **Load Factor and Rehashing:** The load factor is the ratio of the number of elements stored in the hash table to the number of buckets. When the load factor exceeds a certain threshold (typically around 1), `unordered_map` performs rehashing to increase the number of buckets and redistribute elements, maintaining efficiency.


## Basic Usage of `unordered_map` in the C++ Standard Library

[This code demonstrates basic `std::unordered_map` usage.](usage.cpp)


## How `unordered_map` Works

The underlying implementation of `unordered_map` is a hash table, similar to the one implemented previously.  Further details on its workings won't be elaborated here.


## Implementing `unordered_map`

[Detail](Implementation.md)


## Differences from the Standard Library

Compared to `std::unordered_map`, a simplified implementation like this might have the following differences:

This custom `Unordered_map` class is functionally similar to `std::unordered_map` in the STL, but there are several key differences.  Here are some potential discrepancies:

1. **Exception Safety:** `std::unordered_map` provides exception safety guarantees, especially during operations that might throw exceptions.  For example, if the constructor or assignment operator of type `Key` or `Value` might throw, `std::unordered_map` ensures data integrity in case of exceptions. The custom `Unordered_map` might lack this unless the `HashTable` class provides such protection.
2. **Iterator Support:** `std::unordered_map` provides iterators (forward and const) for traversing elements.  The `Unordered_map` class doesn't provide iterators, limiting traversal capabilities.
3. **Method Completeness and Naming:** `std::unordered_map` has a complete set of member functions (`emplace`, `emplace_hint`, `find`, `equal_range`, `bucket`, `load_factor`, `rehash`, etc.). The custom `Unordered_map` has fewer methods, and naming might differ from STL conventions (e.g., `find` returns a boolean instead of an iterator).
4. **Memory Management:** `std::unordered_map` uses highly optimized allocators for efficient memory usage and reuse. The custom `Unordered_map`'s memory management depends on the `HashTable` implementation and might not be as optimized.
5. **Performance:** `std::unordered_map` is extensively optimized for performance (hash function, collision resolution). The custom `Unordered_map`'s performance depends on the `HashTable` implementation.
6. **Portability and Compatibility:** `std::unordered_map` is part of the C++ standard, ensuring consistent behavior across standard-compliant compilers. The custom `Unordered_map` might behave differently across compilers or platforms unless carefully designed for cross-platform compatibility.
7. **Template Parameters:** `std::unordered_map` lets users specify hash and key comparison functions. The custom `Unordered_map` appears to lack this, relying directly on the `HashTable`'s hash function and comparison logic.
8. **Default Construction of Elements:** In `std::unordered_map`, accessing a non-existent key with the subscript operator automatically creates an entry and default-constructs its value. The custom `Unordered_map`'s subscript operator seems to provide similar behavior, but this depends on the `HashTable` class's `insertKey` method implementation.
9. **Copy Control Operations:** `std::unordered_map` defines copy constructor, move constructor, copy assignment operator, move assignment operator, and destructor. The custom `Unordered_map` might not provide all these, relying on the `HashTable` class's implementation.


## Common Interview Questions

1. **What's the difference between `unordered_map` and `map`?**

   **Answer:**

   - **Underlying Implementation:** `unordered_map` uses a hash table; `map` typically uses a red-black tree (a self-balancing binary search tree).
   - **Performance:** For insertion, deletion, and lookup, `unordered_map` offers average O(1) time complexity; `map` provides O(log n).
   - **Order:** Elements in `unordered_map` are unordered; elements in `map` are ordered by key.
   - **Key Type Restrictions:** Keys in `unordered_map` require a hash function and equality comparison; keys in `map` only need to be comparable using the less-than operator.


2. **How does `unordered_map` handle hash collisions?**

   **Answer:** A common method is chaining: elements with the same hash value are stored in a linked list within the same hash bucket.  Lookup involves hashing the key, locating the bucket, and then traversing the linked list.


3. **What are the performance bottlenecks of `unordered_map`?**

   **Answer:**  The main bottlenecks are hash function quality and collision handling. A poor hash function leads to uneven bucket distribution, increasing time complexity.  High load factors (ratio of elements to buckets) also degrade performance, necessitating costly rehashing.


4. **How can you optimize the performance of `unordered_map`?**

   **Answer:**

   - Use a high-quality hash function for even key distribution and reduced collisions.
   - Adjust the load factor threshold to control rehashing frequency (lower reduces collisions but increases memory; higher increases collisions).
   - Pre-allocate space using `reserve()` if the number of elements is known beforehand to reduce rehashing.