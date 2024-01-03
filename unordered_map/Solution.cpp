#include <cstddef>
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <sstream>
#include <string>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable {

  class HashNode {
  public:
    Key key;
    Value value;

    // Constructor creating a node from a Key, Value uses default constructor
    explicit HashNode(const Key &key) : key(key), value() {}

    // Constructor creating a node from a Key and Value
    HashNode(const Key &key, const Value &value) : key(key), value(value) {}

    // Comparison operator overload, compares only by key
    bool operator==(const HashNode &other) const { return key == other.key; }

    bool operator!=(const HashNode &other) const { return key != other.key; }

    bool operator<(const HashNode &other) const { return key < other.key; }

    bool operator>(const HashNode &other) const { return key > other.key; }

    bool operator==(const Key &key_) const { return key == key_; }

    void print() const {
      std::cout << "key: " << key << " value: " << value << " ";
    }
  };

private:
  using Bucket = std::list<HashNode>; // Defines the bucket type as a linked list storing keys
  std::vector<Bucket> buckets;        // Dynamic array storing all buckets
  Hash hashFunction;                  // Hash function object
  size_t tableSize;                   // Size of the hash table, i.e., the number of buckets
  size_t numElements;                 // Number of elements in the hash table

  float maxLoadFactor = 0.75; // Default maximum load factor

  // Calculates the hash value of the key and maps it to the bucket index
  size_t hash(const Key &key) const { return hashFunction(key) % tableSize; }

  // When the number of elements exceeds the capacity defined by the maximum load factor, increase the number of buckets and redistribute all keys
  void rehash(size_t newSize) {
    std::vector<Bucket> newBuckets(newSize); // Creates a new bucket array

    for (Bucket &bucket : buckets) {      // Iterates through old buckets
      for (HashNode &hashNode : bucket) { // Iterates through each key in the bucket
        size_t newIndex =
            hashFunction(hashNode.key) % newSize; // Calculates the new index for the key
        newBuckets[newIndex].push_back(hashNode); // Adds the key to the new bucket
      }
    }
    buckets = std::move(newBuckets); // Updates the bucket array using move semantics
    tableSize = newSize;             // Updates the hash table size
  }

public:
  // Constructor initializes the hash table
  HashTable(size_t size = 10, const Hash &hashFunc = Hash())
      : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

  // Inserts a key into the hash table
  void insert(const Key &key, const Value &value) {
    if ((numElements + 1) > maxLoadFactor * tableSize) { // Checks if rehashing is needed
      rehash(tableSize * 2); // Rehashes, doubling the number of buckets
    }
    size_t index = hash(key);                     // Calculates the index of the key
    std::list<HashNode> &bucket = buckets[index]; // Gets the corresponding bucket
    // If the key is not in the bucket, add it to the bucket
    if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
      bucket.push_back(HashNode(key, value));
      ++numElements; // Increases the number of elements
    }
  }

  void insertKey(const Key &key) { insert(key, Value{}); }

  // Removes a key from the hash table
  void erase(const Key &key) {
    size_t index = hash(key);      // Calculates the index of the key
    auto &bucket = buckets[index]; // Gets the corresponding bucket
    auto it = std::find(bucket.begin(), bucket.end(), key); // Finds the key
    if (it != bucket.end()) {                               // If the key is found
      bucket.erase(it); // Removes the key from the bucket
      numElements--;    // Decreases the number of elements
    }
  }

  // Checks if a key exists in the hash table
  Value *find(const Key &key) {
    size_t index = hash(key);      // Calculates the index of the key
    auto &bucket = buckets[index]; // Gets the corresponding bucket
    // Returns whether the key is in the bucket
    auto ans = std::find(bucket.begin(), bucket.end(), key);
    if (ans != bucket.end()) {
      return &ans->value;
    };
    return nullptr;
  }

  // Gets the number of elements in the hash table
  size_t size() const { return numElements; }

  // Prints all elements in the hash table
  void print() const {
    std::cout << "HashTable elements:" << std::endl;
    for (size_t i = 0; i < buckets.size(); ++i) {
      std::cout << "Bucket " << i << ": ";
      for (const HashNode &element : buckets[i]) {
        element.print();
      }
      std::cout << std::endl;
    }
  }
  void clear() {
    this->buckets.clear();
    this->numElements = 0;
  }
};

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
  Unordered_map<int, int> map;

  int N;
  std::cin >> N;
  getchar();

  std::string line;

  for (int i = 0; i < N; i++) {
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string command;
    iss >> command;

    int key;
    int value;

    if (command == "insert") {
      iss >> key >> value;
      map.insert(key, value);
    }

    if (command == "erase") {
      iss >> key;
      map.erase(key);
    }

    if (command == "find") {
      iss >> key;
      if (map.find(key)) {
        std::cout << "true" << std::endl;
      } else {
        std::cout << "false" << std::endl;
      }
    }

    // size command
    if (command == "size") {
      std::cout << map.size() << std::endl;
    }

    // empty command
    if (command == "empty") {
      if (map.empty()) {
        std::cout << "true" << std::endl;
      } else {
        std::cout << "false" << std::endl;
      }
    }
  }
  return 0;
}