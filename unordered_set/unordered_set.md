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


