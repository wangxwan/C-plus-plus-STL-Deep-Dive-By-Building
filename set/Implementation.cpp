#include "RedBlackTree.h" // Previously implemented Red-Black Tree

template <typename Key> class Set {
public:
  Set() : rbTree() {}

  void insert(const Key &key) { rbTree.insert(key, key); }

  void erase(const Key &key) { rbTree.remove(key); }

  size_t size() { return rbTree.getSize(); }

  bool empty() { return rbTree.empty(); }

  bool contains(const Key &key) { return rbTree.at(key) != nullptr; }

private:
  RedBlackTree<Key, Key> rbTree;
};

int main() {
  Set<int> mySet;

  // Insert elements
  mySet.insert(10);
  mySet.insert(20);
  mySet.insert(30);

  // Print set size
  std::cout << "Current set size: " << mySet.size() << std::endl;

  // Check if the set contains a specific element
  int keyToCheck = 20;
  std::cout << "Set contains element " << keyToCheck << ": "
            << (mySet.contains(keyToCheck) ? "Yes" : "No") << std::endl;

  // Erase an element
  int keyToDelete = 20;
  mySet.erase(keyToDelete);
  std::cout << "After erasing element " << keyToDelete
            << ", current set size: " << mySet.size() << std::endl;

  // Check again if the set contains the erased element
  std::cout << "After erasing element " << keyToDelete << ", set contains element "
            << keyToDelete << ": " << (mySet.contains(keyToCheck) ? "Yes" : "No")
            << std::endl;

  // Check if the set is empty
  std::cout << "Set is empty: " << (mySet.empty() ? "Yes" : "No") << std::endl;

  return 0;
}