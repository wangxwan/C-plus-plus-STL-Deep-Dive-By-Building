

# Differences from the Standard Library

The implemented hash table is a simplified version that uses linked lists to handle hash collisions. This method is also known as separate chaining.  Here are some differences between our implementation and `std::unordered_set` or `std::unordered_map` in the Standard Template Library (STL):

1. **Template Parameters:**
   - Our implementation only accepts the key type `Key` and the hash function `Hash` as template parameters.
   - STL's `std::unordered_set` and `std::unordered_map` have more template parameters, such as key type, value type, hash function, key equality function, and allocator.

2. **Load Factor and Automatic Rehashing:**
   - Our implementation automatically rehashes when the load factor exceeds 0.75, and it only doubles the current size.
   - STL's hash table containers offer more flexibility, allowing adjustment of the load factor and employing more sophisticated rehashing strategies.

3. **Memory Allocation:**
   - Our implementation uses `std::list` to manage collisions, leading to multiple individual memory allocations.
   - STL typically uses more efficient memory allocation strategies, such as pre-allocated memory pools, to reduce allocation overhead and improve performance.

4. **Iterator Support:**
   - Our implementation does not provide iterator support.
   - STL provides full iterator support, allowing users to easily traverse the elements in the container.

5. **Feature Richness:**
   - Our hash table implements basic insertion, deletion, and lookup functionalities.
   - STL's hash table containers provide a richer interface, including methods like `emplace`, `count`, `bucket`, `bucket_count`, `bucket_size`, `load_factor`, `max_load_factor`, `rehash`, and `reserve`.

6. **Exception Safety:**
   - Our implementation doesn't explicitly handle exception safety.
   - STL implementations typically guarantee basic exception safety and provide strong exception safety guarantees in some operations.

7. **Optimization:**
   - Our implementation is a basic hash table and may not be optimized for performance.
   - STL implementations are highly optimized to provide good performance, especially with large datasets.

8. **Platform Compatibility and Portability:**
   - Our implementation is theoretically cross-platform but might require adjustments for different platforms.
   - STL containers are widely used across various platforms and extensively tested by the community, offering high compatibility and stability.

9. **Interface Consistency:**
   - Our implementation might not adhere to the standard naming and behavior of STL container interfaces.
   - STL containers follow consistent interface and naming conventions, aiding programmer understanding and usage.


These differences don't necessarily mean our implementation is inferior; rather, they highlight that STL containers are designed with many complex scenarios and requirements in mind, making them very powerful in terms of generality, performance, and ease of use. User-defined data structures are often better suited for solving specific problems or use cases, while STL containers provide good default choices for most common situations.