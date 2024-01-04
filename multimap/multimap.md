# `std::multimap`

`std::multimap` is an associative container in the C++ Standard Template Library (STL) that stores key-value pairs, allowing duplicate keys.

## Characteristics

**Key Multiplicity:** Unlike `std::map`, `std::multimap` permits multiple elements to have the same key. This makes `multimap` ideal for scenarios where multiple values need to be grouped under a single key.

**Ordered Elements:** Elements in `std::multimap` are automatically sorted based on their keys. By default, it uses `std::less` for key comparison, resulting in ascending order.  A custom comparison function can be provided for different sorting logic.

**Red-Black Tree Implementation:** Most STL implementations use a self-balancing binary search tree (like a red-black tree) to implement `multimap`. This ensures logarithmic time complexity (O(log n)) for most operations (insertion, lookup, deletion) even in the worst case, where n is the number of elements.

**Key Modification Not Directly Supported:** Because elements in `multimap` are sorted by key, directly modifying a key can disrupt the container's internal order.  To change a key, the usual approach is to erase the old element and insert a new one.

## Performance

**Insertion:** The average time complexity of insertion is O(log n).  The performance isn't affected by inserting elements with duplicate keys.

**Lookup:**  The average time complexity of finding elements with a given key is also O(log n).  If multiple elements share the same key, STL provides the `equal_range` function to efficiently retrieve the range of all elements with that key.

**Deletion:** Deleting elements with a specific key has an average time complexity of O(log n). Deleting all elements with a specific key remains logarithmic, although the actual number of operations increases.


## Basic Usage in the C++ Standard Library

[This code demonstrates basic `std::multimap` usage.](usage.cpp)


