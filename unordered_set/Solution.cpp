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

    // Construct a node from a Key, using the default constructor for Value.
    explicit HashNode(const Key &key) : key(key), value() {}

    // Construct a node from a Key and a Value.
    HashNode(const Key &key, const Value &value) : key(key), value(value) {}

    // Overload comparison operators, comparing only by key.
    bool operator==(const HashNode &other) const { return key == other.key; }

    bool operator!=(const HashNode &other) const { return key != other.key; }

    bool operator<(const HashNode &other) const { return key < other.key; }

    bool operator>(const HashNode &other) const { return key > other.key; }

    bool operator==(const Key &key_) const { return key == key_; }

    void print() const {
      std::cout << key << " " << value << " ";
    }
  };

private:
  using Bucket = std::list<HashNode>; // Define the bucket type as a list of HashNodes.
  std::vector<Bucket> buckets;        // Dynamic array storing all buckets.
  Hash hashFunction;                  // Hash function object.
  size_t tableSize;                   // Size of the hash table (number of buckets).
  size_t numElements;                 // Number of elements in the hash table.

  float maxLoadFactor = 0.75; // Default maximum load factor.

  // Calculate the hash value of a key and map it to a bucket index.
  size_t hash(const Key &key) const { return hashFunction(key) % tableSize; }

  // Increase the number of buckets and redistribute all keys when the number of elements exceeds the capacity defined by the maximum load factor.
  void rehash(size_t newSize) {
    std::vector<Bucket> newBuckets(newSize); // Create a new bucket array.

    for (Bucket &bucket : buckets) {      // Iterate through old buckets.
      for (HashNode &hashNode : bucket) { // Iterate through each key in the bucket.
        size_t newIndex =
            hashFunction(hashNode.key) % newSize; // Calculate the new index for the key.
        newBuckets[newIndex].push_back(hashNode); // Add the key to the new bucket.
      }
    }
    buckets = std::move(newBuckets); // Update the bucket array using move semantics.
    tableSize = newSize;             // Update the hash table size.
  }

public:
  // Constructor to initialize the hash table.
  HashTable(size_t size = 10, const Hash &hashFunc = Hash())
      : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

  // Insert a key-value pair into the hash table.
  void insert(const Key &key, const Value &value) {
    if ((numElements + 1) > maxLoadFactor * tableSize) { // Check if rehashing is needed.
      if (tableSize == 0) tableSize = 1;
      rehash(tableSize * 2); // Rehash, doubling the number of buckets.
    }
    size_t index = hash(key);                     // Calculate the index of the key.
    std::list<HashNode> &bucket = buckets[index]; // Get the corresponding bucket.
    // Add the key-value pair to the bucket if the key is not already present.
    if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
      bucket.push_back(HashNode(key, value));
      ++numElements; // Increment the element count.
    }
  }

  void insertKey(const Key &key) { insert(key, Value{}); }

  // Remove a key from the hash table.
  void erase(const Key &key) {
    size_t index = hash(key);      // Calculate the index of the key.
    auto &bucket = buckets[index]; // Get the corresponding bucket.
    auto it = std::find(bucket.begin(), bucket.end(), key); // Find the key.
    if (it != bucket.end()) {                               // If the key is found.
      bucket.erase(it); // Remove the key from the bucket.
      numElements--;    // Decrement the element count.
    }
  }

  // Find a key in the hash table.
  Value *find(const Key &key) {
    size_t index = hash(key);      // Calculate the index of the key.
    auto &bucket = buckets[index]; // Get the corresponding bucket.
    // Return a pointer to the value if the key is found, otherwise return nullptr.
    auto ans = std::find(bucket.begin(), bucket.end(), key);
    if (ans != bucket.end()) {
      return &ans->value;
    };
    return nullptr;
  }

  // Get the number of elements in the hash table.
  size_t size() const { return numElements; }

  // Print all elements in the hash table.
  void print() const {
    for (size_t i = 0; i < buckets.size(); ++i) {
      for (const HashNode &element : buckets[i]) {
        element.print();
      }
      std::cout << std::endl;
    }
  }
  void clear() {
    this->buckets.clear();
    this->numElements = 0;
    this->tableSize = 0;
  }
};

template <typename Key> class Unordered_set {
public:
  Unordered_set() : hashtable(){};

  ~Unordered_set() {}

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
  Unordered_set<int> mySet;
  int N;
  std::cin >> N;
  getchar();

  std::string line;
  for (int i = 0; i < N; i++) {
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string command;
    iss >> command;

    int element;

    if (command == "insert") {
        iss >> element;
        mySet.insert(element);
    }

    if (command == "erase") {
        iss >> element;
        mySet.erase(element);
    }

    if (command == "find") {
        iss >> element;
        std::cout << (mySet.find(element) ? "true" : "false") << std::endl;
    }

    if (command == "size") {
        std::cout << mySet.size() << std::endl;
    }

    if (command == "empty") {
        std::cout << (mySet.empty() ? "true" : "false") << std::endl;
    }
  }
  return 0;
}