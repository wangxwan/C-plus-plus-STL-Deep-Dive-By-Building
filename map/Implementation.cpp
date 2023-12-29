#include "RedBlackTree.h" // Previously implemented red-black tree
#include <iostream>
#include <utility> // For std::pair

// Assuming RedBlackTree is already defined, where Key is the map's key type and Value is the map's value type

template <typename Key, typename Value> class Map {
public:
  Map() : rbTree() {}

  void insert(const Key &key, const Value &value) { rbTree.insert(key, value); }

  void erase(const Key &key) { rbTree.remove(key); }

  size_t size() { return rbTree.getSize(); }

  bool empty() const { return rbTree.empty(); }

  bool contains(const Key &key) { return rbTree.at(key) != nullptr; }

  Value &at(const Key &key) {
    Value *foundVal = rbTree.at(key);
    if (foundVal) {
      return *foundVal;
    } else {
      throw std::out_of_range("Key not found");
    }
  }

  Value &operator[](const Key &key) {
    Value *foundVal = rbTree.at(key);
    if (foundVal) {
      // If key exists, return the associated value
      return *foundVal; // Or, return the value associated with the found key
    } else {
      // If key doesn't exist, insert a new key-value pair and return a reference to the newly inserted value
      Value defaultValue;
      rbTree.insert(key, defaultValue);
      return *rbTree.at(key);
    }
  }

private:
  RedBlackTree<Key, Value> rbTree;
};

// main function
int main() {
  Map<int, std::string> map;

  // Insert key-value pairs
  map.insert(1, "Apple");
  map.insert(2, "Banana");
  map.insert(3, "Cherry");

  // Print size
  std::cout << "Current Map size: " << map.size() << std::endl;

  // Access elements
  try {
    std::cout << "Value for key 1: " << map.at(1) << std::endl;
    std::cout << "Value for key 2: " << map.at(2) << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // Check if a key exists
  int keyToCheck = 3;
  std::cout << "Map contains key " << keyToCheck << ": "
            << (map.contains(keyToCheck) ? "Yes" : "No") << std::endl;

  // Use [] operator to access or create elements
  std::cout << "Value for key 4 (didn't exist before, will be created): " << map[4]
            << std::endl;

  // Delete an element
  int keyToDelete = 2;
  std::cout << "Deleting key " << keyToDelete << std::endl;
  map.erase(keyToDelete);

  // Print size again
  std::cout << "After deleting key " << keyToDelete << ", current Map size: " << map.size()
            << std::endl;

  // Use [] operator to assign a value to an element
  map[4] = "Pear";
  std::cout << "Value for key 4: " << map[4] << '\n';
  return 0;
}