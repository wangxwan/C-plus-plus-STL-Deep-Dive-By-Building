# `unordered_map`

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


