#include "hashTable.h" // Previously implemented hash table
#include <cstddef>

template <typename Key> class Unordered_set {
public:
  Unordered_set() : hashtable(){};

  ~Unordered_set(){}

  bool empty() const noexcept { return hashtable.size() == 0; }

  size_t size() const noexcept { return hashtable.size(); }

  void clear() noexcept { hashtable.clear(); }

  void insert(Key key) { hashtable.insertKey(key); }

  void erase(Key key) { hashtable.erase(key); }

  bool find(const Key &key) { return hashtable.find(key) != nullptr; }

private:
  HashTable<Key, Key> hashtable;
};

int main() {
  // Create an Unordered_set of integers
  Unordered_set<int> intSet;

  // Insert some numbers
  intSet.insert(1);
  intSet.insert(2);
  intSet.insert(3);

  // Check if the set is empty
  std::cout << "Is the set empty? " << (intSet.empty() ? "Yes" : "No") << std::endl;

  // Check the size of the set
  std::cout << "Size of the set: " << intSet.size() << std::endl;

  // Find an element
  std::cout << "Is 2 in the set? " << (intSet.find(2) ? "Yes" : "No") << std::endl;

  // Erase an element
  intSet.erase(2);
  std::cout << "After erasing 2, is 2 still in the set? " << (intSet.find(2) ? "Yes" : "No") << std::endl;

  // Clear the set
  intSet.clear();
  std::cout << "After clearing, is the set empty? " << (intSet.empty() ? "Yes" : "No") << std::endl;

  // Create an Unordered_set of strings
  Unordered_set<std::string> stringSet;

  // Insert some strings
  stringSet.insert("apple");
  stringSet.insert("banana");
  stringSet.insert("cherry");

  // Find a string
  std::cout << "Is 'banana' in the set? " << (stringSet.find("banana") ? "Yes" : "No") << std::endl;

  // Erase a string
  stringSet.erase("banana");
  std::cout << "After erasing 'banana', is 'banana' still in the set? " << (stringSet.find("banana") ? "Yes" : "No") << std::endl;

  return 0;
}