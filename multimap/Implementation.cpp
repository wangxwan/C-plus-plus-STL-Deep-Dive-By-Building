#include "RedBlackTree.h" // Previously implemented Red-Black tree
#include <cstddef>
#include <iostream>
#include <list>

template <typename Key, typename Value> class MultiMap {
public:
  using ValueType = std::list<Value>; // Change Value type to list

  MultiMap() : rbTree(), size(0) {}

  void insert(const Key &key, const Value &value) {
    // Check if the current key already exists
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
      // If the key already exists, add the value to the corresponding list
      existingValues->push_back(value);
    } else {
      // If the key does not exist, create a new list, add the value, and then insert it into the red-black tree
      ValueType values;
      values.push_back(value);
      rbTree.insert(key, values);
    }
    size++;
  }

  void remove(const Key &key) {
    // Remove the entire key, including all its values
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
      size -= existingValues->size();
      rbTree.remove(key);
    }
  }

  void remove(const Key &key, const Value &value) {
    // Find the current key
    ValueType *existingValues = rbTree.at(key);
    if (existingValues) {
      // Remove the given value
      existingValues->remove(value);
      size--;
      // If the list is empty after removing the value, remove the key as well
      if (existingValues->empty()) {
        rbTree.remove(key);
      }
    }
  }

  ValueType *at(const Key &key) {
    // Get the list of all values corresponding to the key
    return rbTree.at(key);
  }

  int getSize() { return size; }

  bool empty() { return size == 0; }

private:
  RedBlackTree<Key, ValueType> rbTree; // Use ValueType as the value type for the red-black tree
  size_t size;
};

int main() {
  // Create a MultiMap instance with Key type as std::string and Value type as int
  MultiMap<std::string, int> myMultiMap;

  // Insert some key-value pairs
  myMultiMap.insert("apple", 10);
  myMultiMap.insert("banana", 20);
  myMultiMap.insert("apple", 30); // "apple" can have multiple values

  // Get and print all values for the key "apple"
  auto appleValues = myMultiMap.at("apple");
  if (appleValues) {
    std::cout << "Values for 'apple':";
    for (const auto &val : *appleValues) {
      std::cout << val << ", ";
    }
    std::cout << '\n';
  }

  // Remove all values for the key "banana" from the MultiMap
  myMultiMap.remove("banana");

  // Remove the value 30 for the key "apple" from the MultiMap
  myMultiMap.remove("apple", 30);

  // Check if the MultiMap is empty
  if (!myMultiMap.empty()) {
    std::cout << "The MultiMap is not empty, it has " << myMultiMap.getSize()
              << " elements." << std::endl;
  }

  return 0;
}