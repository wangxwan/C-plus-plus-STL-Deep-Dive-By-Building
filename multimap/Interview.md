# Common Interview Questions

1. **Explain what a `multimap` is and how it differs from a `map`?**

   **Answer:** A `multimap` is an associative container that allows multiple values to be associated with a single key. This means a `multimap` can have multiple elements with the same key, each key mapping to a sequence of values. In contrast, a `map` is an associative container that maps keys to single values; duplicate keys are not allowed.

2. **In what situations would you use a `multimap` instead of other container types?**

   **Answer:** `multimap` is suitable for scenarios where you need to maintain a mapping relationship between a key and multiple values. For example, if you need to store book information based on author's name, where one author might have written multiple books, using a `multimap` allows you to easily retrieve all books by a given author. Compared to using `map<key, list<value>>`, `multimap` provides a more intuitive and convenient way to manage this data.

3. **How do you search for all values associated with a specific key in a `multimap`?**

   **Answer:** Searching for all values associated with a specific key in a `multimap` can be done using iterators. First, use the `equal_range` method to obtain a pair of iterators that encompass the first and one-past-the-last elements for the given key. Then, you can iterate through this range to access all the corresponding values.

4. **How do you remove a specific key-value pair from a `multimap`?**

   **Answer:** To remove a specific key-value pair from a `multimap`, you need to iterate through all the elements associated with that key and compare the values. When you find the matching key-value pair, use the `erase` method on the iterator pointing to that element to delete it.

5. **What is special about inserting data into a `multimap`?**

   **Answer:** When inserting data into a `multimap`, you don't need to check if the key already exists. Since `multimap` allows duplicate keys, the insertion operation simply adds a new key-value pair to the container, even if the key already has one or more associated values. You can use the `insert` method to perform the insertion.

6. **How does a `multimap` guarantee element order?**

   **Answer:** A `multimap` typically uses a self-balancing binary search tree (like a red-black tree) to store elements, which guarantees that elements are stored in sorted order by key. Therefore, even after insertion and deletion operations, all elements remain ordered. The comparison of keys defaults to the `less` function object, but a custom comparison function can also be provided when creating the `multimap`.