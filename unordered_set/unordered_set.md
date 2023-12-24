# `unordered_set`

[Problem Description](Problem.md)

[Solution](Solution.cpp)


The C++ Standard Template Library (STL) is a crucial part of C++, providing a range of generic data structures and algorithms.

Within the STL, `std::unordered_set` is an unordered associative container implemented using a hash table. This document delves into the inner workings of `std::unordered_set`, covering aspects such as hash tables, collision resolution, iterators, and performance optimization.

## Usage

[This code demonstrates the basic usage of `unordered_set`.](usage.cpp)


## `unordered_set` Internal Analysis

`unordered_set` is implemented using a hash table.  Our previous hash table implementation used key-value pairs.  `unordered_set` simply encapsulates this, removing the value component of the key-value pair.  The hash table implementation is detailed in a previous document and will not be repeated here.


## `unordered_set` Code Implementation

Based on a previously implemented HashTable (defined and implemented in `hashTable.h`):

[Detail](Implementation.md)


## Differences from the Standard Library

This code is a highly simplified simulation, not a precise implementation of `std::unordered_set`.  Here are key differences:

1. **Functionality:** `std::unordered_set` offers a complete feature set including iterator support, element access, bucket interface, load factor control, customizable hash and equality policies, etc.  Our `Unordered_set` is basic.
2. **Iterator Support:** `std::unordered_set` provides iterators for traversal.  Our implementation lacks this.
3. **Exception Safety:** `std::unordered_set` members usually offer strong exception guarantees.  Our implementation lacks exception handling.
4. **Type Restrictions:** `std::unordered_set` requires hashable and equality-comparable key types.  Our implementation implicitly requires this but doesn't explicitly state it.
5. **Memory Management:** `std::unordered_set` optimizes memory management (e.g., reclaiming memory after deletion). Our implementation doesn't detail memory management.
6. **Performance:** `std::unordered_set` is optimized for performance. Our `Unordered_set`'s performance depends on the `HashTable` implementation.
7. **Method Naming and Return Types:** Standard library uses standard naming conventions (e.g., `find` returns an iterator, not a boolean).
8. **Portability:** `std::unordered_set` is standard library; behavior is consistent across platforms. Our `Unordered_set` may not be as portable.
9. **Constructors and Destructors:** `std::unordered_set` provides various constructors (copy, move, etc.). Our implementation only provides a default constructor and destructor.
10. **Copy Control:** `std::unordered_set` defines copy constructor, move constructor, copy assignment operator, and move assignment operator.  Our class doesn't explicitly define these, potentially leading to issues if `HashTable` doesn't handle them correctly.


For learning or simplified use in specific contexts, our `Unordered_set` might suffice. However, for a robust, general-purpose container, `std::unordered_set` is far more reliable and efficient.


## Common Interview Questions on `unordered_set`

1. What are the differences between `std::unordered_set` and `std::set`?

The main differences lie in their underlying data structures and performance characteristics. `std::set` uses a red-black tree, maintaining sorted elements, while `std::unordered_set` uses a hash table, with no guaranteed element order.  `std::unordered_set` generally offers faster insertion, deletion, and lookup, but doesn't support ordered access or range queries.

2. How does `std::unordered_set` handle collisions?

`std::unordered_set` uses separate chaining (linked lists) to handle hash collisions. When two elements hash to the same location, they are stored in a linked list within that bucket.  Lookup involves hashing and then traversing the linked list in the corresponding bucket.

3. How can you customize the hash function and equality function for elements in `std::unordered_set`?

When declaring `std::unordered_set`, you can provide custom hash and equality predicate types as template arguments. The custom hash function must take a single argument (the element type) and return its hash value. The custom equality function compares two elements for equality.

4. What is the iterator type of `std::unordered_set`, and how are they affected by modifications to the hash table?

`std::unordered_set` provides forward iterators (both const and non-const). Iterators traverse the hash table's buckets and then the linked lists within each bucket. Adding or removing elements might cause rehashing, potentially invalidating existing iterators. However, deleting the element the iterator currently points to is safe.

5. How can you optimize the performance of `std::unordered_set`?

Optimizing `std::unordered_set` performance often involves choosing a good hash function to minimize collisions and maintain a uniform element distribution. You can increase the number of buckets using `rehash` or pre-allocate sufficient space using `reserve` to reduce rehashing.

6. How does `std::unordered_set` handle element deletion?

Deletion involves finding the bucket corresponding to the element's hash value and then removing the element from the linked list in that bucket.  The average time complexity is O(1), but it can be O(n) in the worst case (if a bucket has many elements).