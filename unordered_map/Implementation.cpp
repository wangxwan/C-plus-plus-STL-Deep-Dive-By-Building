#include "hashTable.h" // Previously implemented hash table
#include <cstddef>

template <typename Key, typename Value> class Unordered_map {
private:
  HashTable<Key, Value> hashtable;

public:
  Unordered_map() : hashtable(){};

  ~Unordered_map() {}

  bool empty() const noexcept { return hashtable.size() == 0; }

  size_t size() const noexcept { return hashtable.size(); }

  void clear() noexcept { hashtable.clear(); }

  void insert(const Key &key, const Value &value) {
    hashtable.insert(key, value);
  }

  void erase(const Key &key) { hashtable.erase(key); }

  bool find(const Key &key) { return hashtable.find(key) != nullptr; }

  Value &operator[](const Key &key) {
    Value *ans = hashtable.find(key);
    if (ans != nullptr) {
      return *ans;
    }
    hashtable.insertKey(key);
    ans = hashtable.find(key);
    return *ans;
  }
};

int main() {
  // Create an Unordered_map with std::string keys and values
  Unordered_map<std::string, std::string> map;

  // Insert some key-value pairs
  map.insert("apple", "苹果");
  map.insert("banana", "香蕉");
  map.insert("cherry", "樱桃");

  // Check if the map is empty
  std::cout << "Is the map empty? " << (map.empty() ? "Yes" : "No") << std::endl;

  // Get the size of the map
  std::cout << "Size of the map: " << map.size() << std::endl;

  // Access an element
  std::cout << "The Chinese for apple is: " << map["apple"] << std::endl;

  // Modify an element
  map["apple"] = "Red apple";
  std::cout << "After modification, the Chinese for apple is: " << map["apple"] << std::endl;

  // Insert a new key-value pair using [] operator
  map["orange"] = "Orange";
  std::cout << "The Chinese for orange is: " << map["orange"] << std::endl;

  // Find an element
  std::cout << "Is cherry in the map? " << (map.find("cherry") ? "Yes" : "No") << std::endl;

  // Delete an element
  map.erase("banana");
  std::cout << "After deleting banana, is banana still in the map? " << (map.find("banana") ? "Yes" : "No") << std::endl;

  // Clear the map
  map.clear();
  std::cout << "After clearing, is the map empty? " << (map.empty() ? "Yes" : "No") << std::endl;

  return 0;
}