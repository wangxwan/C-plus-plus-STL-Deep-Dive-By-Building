# HashTable

[Problem Description](Problem.md)

[Solution](Implementation.cpp)


In the Standard Template Library (STL), the `HashTable` is a crucial underlying data structure.  Unordered associative containers like `unordered_set` and `unordered_map` are internally implemented based on hash tables. This article delves into the internal workings of `HashTable`, covering aspects such as hash functions, collision resolution, iterators, and performance optimization.

## HashTable Internal Analysis

1. Hash Table Fundamentals

A hash table is a data structure that uses a hash function to map keys to indices.

The hash function maps an input of arbitrary size to a fixed-size output, the hash value. This hash value serves as the index for storing key-value pairs in an array.

2. Collision Resolution

Since the mapping of a hash function is not one-to-one, collisions can occur where two different keys map to the same index.  This can be resolved using separate chaining, where each slot in the hash table maintains a linked list. Elements with the same hash value are stored in the linked list associated with that slot.

3. Hash Table Resizing and `rehashing`

To prevent excessively long linked lists in the hash table, which would degrade performance, resizing is performed when necessary.

The resizing process involves recalculating the hash values of all elements and distributing them into a new, larger hash table. This process is called `rehashing`.

4. Performance Optimization

To enhance performance, `HashTable` implementations typically incorporate several optimization strategies.

These include using quadratic probing, custom allocators, and memory pools to reduce memory allocation overhead and improve access speed.

5. Concurrency and Thread Safety

In a multithreaded environment, ensuring the correctness of the data structure is paramount.

Multithreaded hash table implementations usually consider concurrency and thread safety, employing locks or other mechanisms to protect the shared data structure.

`rehashing` is triggered when the length of any `bucket`'s linked list exceeds 1. Each `bucket` uses a linked list to store colliding elements.


## HashTable Code Implementation

Implementing a full-fledged hash table involves complex hash table design and management, including hash functions, collision resolution, and `rehashing`.

[Detail](Implementation.md)

