# `std::map` in C++

In the C++ Standard Template Library (STL), `std::map` is a highly useful and powerful container that provides a key-value pair storage mechanism. This makes `std::map` ideal for handling associative data with unique keys.

## Characteristics of `std::map`

- **Key-Value Pair Storage:** `std::map` stores data in the form of key-value pairs, where each key is unique and associated with a value.
- **Automatic Sorting:** `std::map` internally uses a self-balancing binary search tree (typically a red-black tree) to store elements, resulting in automatic sorting of elements based on their keys.
- **Unique Keys:** Keys in `std::map` must be unique.  Attempting to insert a key that already exists will fail (or replace the existing value, depending on the insertion method).
- **Direct Access:** Elements in `std::map` can be accessed directly using their keys, providing efficient lookup capabilities.
- **Flexible Element Operations:** `std::map` offers a rich set of element operations, including insertion, deletion, and searching.


## Performance of `std::map`

- **Insertion:** The time complexity of insertion is O(log n), where n is the number of elements in the `std::map`. This is because the appropriate position to insert the new element needs to be found within the balanced binary search tree.
- **Lookup:** The time complexity of lookup is also O(log n).  Due to the ordered nature of `std::map`, any key can be located quickly.
- **Deletion:** The time complexity of deletion is likewise O(log n). The element to be deleted needs to be found and removed while maintaining the balance of the tree.
- **Iteration:** Iterating through `std::map` has a time complexity of O(n), as each element in the container needs to be visited.