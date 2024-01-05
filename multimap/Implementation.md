# Implementation Details

Because `multimap` requires ordering, it's typically implemented using a red-black tree. However, a basic red-black tree implementation doesn't inherently support duplicate keys. Therefore, the `Value` template parameter in the red-black tree cannot be a simple data type; a `std::list` or `std::vector` is used to store multiple `Value`s for a single key.

[This code snippet shows a possible implementation using a previously implemented RedBlackTree (assumed to be available).](Implementation.cpp)

1. **Constructor**

```c++
MultiMap() : rbTree(), size(0) {}
```

The constructor initializes the internal red-black tree `rbTree` and sets the number of elements in the multimap, `size`, to 0.

2. **`insert` Function**

```c++
void insert(const Key &key, const Value &value) {
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
        existingValues->push_back(value);
    } else {
        ValueType values;
        values.push_back(value);
        rbTree.insert(key, values);
    }
    size++;
}
```

The `insert` function adds a new key-value pair to the multimap. If the key already exists, the value is appended to the corresponding list. If the key does not exist, a new list containing the value is created and inserted into the red-black tree. In either case, the total number of elements in the multimap, `size`, is incremented by 1.

3. **`remove` Function (Removing the Entire Key)**

```c++
void remove(const Key &key) {
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
        size -= existingValues->size();
        rbTree.remove(key);
    }
}
```

This `remove` function removes all values associated with the specified key, as well as the key itself, from the multimap. This operation decrements the total number of elements, `size`, in the multimap.

4. **`remove` Function (Removing a Specific Value from a Specific Key)**

```c++
void remove(const Key &key, const Value &value) {
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
        existingValues->remove(value);
        size--;
        if (existingValues->empty()) {
            rbTree.remove(key);
        }
    }
}
```

This overloaded `remove` function removes a specific value associated with the specified key from the multimap. If, after removing the specific value, the list of values associated with that key becomes empty, the key is also removed from the red-black tree.

5. **`at` Function**

```c++
ValueType *at(const Key &key) {
    return rbTree.at(key);
}
```

The `at` function retrieves a pointer to the list of values associated with the specified key.  If the key does not exist, it returns `nullptr`.

6. **`getSize` Function**

```c++
int getSize() { return size; }
```

The `getSize` function returns the total number of elements (values) in the multimap.

7. **`empty` Function**

```c++
bool empty() { return size == 0; }
```

The `empty` function checks if the multimap is empty. If `size` is 0, indicating that the multimap contains no elements, the function returns `true`; otherwise, it returns `false`.