# `unordered_set` Code Implementation

Based on a previously implemented HashTable (defined and implemented in `hashTable.h`):

[This code incorporates a previously implemented hash table.](Implementation.cpp)

This `Unordered_set` class is a template class for storing a set of unique elements. It uses the `HashTable` class as its underlying data structure.  Here's a breakdown of each member function:

1. **Constructor** `Unordered_set() : hashtable() {}`:
   - Default constructor for `Unordered_set`.
   - Initializes the `hashtable` object using a member initializer list.
   - Relies on `HashTable` having its own default constructor.
2. **Destructor** `~Unordered_set() {}`:
   - Default destructor for `Unordered_set`.  Performs no actions. Resource deallocation should be handled by the `HashTable` destructor if necessary.
3. **`empty`** `bool empty() const noexcept { return hashtable.size() == 0; }`:
   - Checks if the `Unordered_set` is empty.
   - Calls the underlying `HashTable`'s `size` method.
4. **`size`** `size_t size() const noexcept { return hashtable.size(); }`:
   - Returns the number of elements in the set.
   - Directly returns the result of the underlying `HashTable`'s `size` method.
5. **`clear`** `void clear() noexcept { hashtable.clear(); }`:
   - Clears all elements from the set.
   - Calls the underlying `HashTable`'s `clear` method.
6. **`insert`** `void insert(Key key) { hashtable.insertKey(key); }`:
   - Inserts a new element into the set.
   - Calls the underlying `HashTable`'s `insertKey` method.  `hashtable` should handle uniqueness.
7. **`erase`** `void erase(Key key) { hashtable.erase(key); }`:
   - Removes an element from the set.
   - Calls the underlying `HashTable`'s `erase` method.
8. **`find`** `bool find(const Key &key) { return hashtable.find(key) != nullptr; }`:
   - Checks if a given `key` exists in the set.
   - Calls the underlying `HashTable`'s `find` method. Returns `true` if found, `false` otherwise.