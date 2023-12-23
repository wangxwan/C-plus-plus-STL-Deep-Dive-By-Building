# `unordered_set`

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