# Implementing `unordered_map`

[This code uses the previously implemented hash table.](Implementation.cpp)


1. **Constructor:** `Unordered_map() : hashtable() {}`: This is the default constructor for `Unordered_map`. It uses member initializer list syntax to initialize the `hashtable` object.  It assumes `HashTable` has a default no-argument constructor.
2. **Destructor:** `~Unordered_map() {}`: This is the destructor for `Unordered_map`. It's a default destructor and doesn't perform any special actions. If the `HashTable` class allocates dynamic memory or other resources, it should handle releasing those resources in its destructor.
3. **`empty`:** `bool empty() const noexcept { return hashtable.size() == 0; }`: Checks if the `Unordered_map` is empty. It calls the underlying `HashTable`'s `size` method and checks if the return value is `0`.
4. **`size`:** `size_t size() const noexcept { return hashtable.size(); }`: Returns the number of elements in the map. It directly returns the result of the underlying `HashTable`'s `size` method.
5. **`clear`:** `void clear() noexcept { hashtable.clear(); }`: Clears all elements from the map. It calls the underlying `HashTable`'s `clear` method.
6. **`insert`:** `void insert(const Key &key, const Value &value) { hashtable.insert(key, value); }`: Inserts a new key-value pair. It calls the underlying `HashTable`'s `insert` method. The behavior if the key already exists depends on the `HashTable` implementation (might replace or reject).
7. **`erase`:** `void erase(const Key &key) { hashtable.erase(key); }`: Removes an element. It calls the underlying `HashTable`'s `erase` method.
8. **`find`:** `bool find(const Key &key) { return hashtable.find(key) != nullptr; }`: Checks if a key exists. It calls the underlying `HashTable`'s `find` method and checks if the returned pointer is not `nullptr`.
9. **Subscript Operator:** `Value &operator[](const Key &key)`: Overloads the subscript operator for array-like access. It tries to find the key; if found, returns a reference to the value. If not found, it inserts a new key (potentially default-constructing a `Value`) and returns a reference to the newly inserted value.