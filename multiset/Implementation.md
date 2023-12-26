# Implementing `multiset`

Based on a previously implemented `RedBlackTree` (assuming its class definition and implementation are in `RedBlackTree.h`):

[This code assumes a pre-existing Red-Black Tree implementation.](Implementation.cpp)

1. **Constructor:**

```cpp
MultiSet() : sz(0) {} // Constructor
```

The constructor initializes an empty `MultiSet` object, with the `sz` member variable set to 0, indicating no elements in the set.

2. **Destructor:**

```cpp
~MultiSet() {} // Destructor
```

The destructor has no special implementation, relying on the automatic memory management of `RedBlackTree`. When the `MultiSet` object is destroyed, its member variable `rbTree` will also be automatically destroyed.

3. `insert`

```cpp
void insert(const Key &key) {
  auto count = rbTree.at(key);
  if (count != nullptr) {
    (*count)++;
    sz++;
    return;
  }
  rbTree.insert(key, 1);
  sz++;
}
```

The `insert` function first tries to get the count for the key from the red-black tree. If the key exists, its count is incremented, and the set size is increased. If the key doesn't exist, it's inserted into the red-black tree with a count of 1, and the set size is increased.

4. `erase`

```cpp
void erase(const Key &key) {
  auto count = rbTree.at(key);
  if (count == nullptr) {
    return;
  }
  (*count)--;
  sz--;
  if (*count == 0) {
    rbTree.remove(key);
  }
}
```

The `erase` function first finds the count for the given key. If the key doesn't exist, it returns. If it exists, the count is decremented, and the set size is decreased. If the count becomes 0, the key is removed from the red-black tree.

5. `size`

```cpp
size_t size() const { return sz; }
```

The `size` function returns the number of elements in the `MultiSet`, directly returning the value of the `sz` member variable.

6. `empty`

```cpp
bool empty() const { return sz == 0; }
```

The `empty` function checks if the `MultiSet` is empty. If `sz` is 0, the set is empty, and the function returns `true`; otherwise, it returns `false`.

7. `count`

```cpp
size_t count(const Key &key) {
  auto num = rbTree.at(key);
  if (num != nullptr) {
    return *num;
  }
  return 0;
}
```

The `count` function returns the number of occurrences of the given key in the `MultiSet`. It queries the red-black tree to get the key's count. If the key exists, it returns its count; otherwise, it returns 0.

8. `clear`

```cpp
void clear() {
  sz = 0;
  rbTree.clear();
}
```

The `clear` function clears all elements from the `MultiSet`. It sets the `sz` member variable to 0 and calls the red-black tree's `clear` function to remove all elements.