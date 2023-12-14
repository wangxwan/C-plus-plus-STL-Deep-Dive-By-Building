# HashTable Code Implementation

Implementing a full-fledged hash table involves complex hash table design and management, including hash functions, collision resolution, and `rehashing`.

Due to space and complexity constraints, [a simplified hash table is provided here](Implementation.cpp), demonstrating basic functionalities such as insertion, deletion, lookup, printing, and size retrieval.

Note that this is a simplified example; actual hash table implementations are significantly more complex and efficient.

1. `hash` Function:

   ```cpp
   size_t hash(const Key &key) const { return hashFunction(key) % tableSize; }
   ```

   This private member function calculates the hash value of a key and returns the index used to locate the bucket. It uses the modulo operator with the table size to ensure the index is within the valid range.  It leverages a provided hash function (`hashFunction`) for key hashing.

2. `rehash` Function:

   ```cpp
   void rehash(size_t newSize) {
       std::vector<Bucket> newBuckets(newSize); // Creates a new bucket array.

       for (Bucket &bucket : buckets) {      // Iterates through the old buckets.
         for (HashNode &hashNode : bucket) { // Iterates through each key in the bucket.
             size_t newIndex =
                 hashFunction(hashNode.key) % newSize; // Calculates the new index for the key.
             newBuckets[newIndex].push_back(hashNode); // Adds the key to the new bucket.
         }
       }
       buckets = std::move(newBuckets); // Updates the bucket array using move semantics.
       tableSize = newSize;             // Updates the hash table size.
   }
   ```

   This private member function is called when the hash table's load factor exceeds a predefined maximum load factor. It reallocates and initializes a larger bucket array, remapping all keys to the new buckets. This process is called rehashing. The new number of buckets is typically double the current number.

3. `HashTable` Constructor:

   ```cpp
   HashTable(size_t size = 10, const Hash &hashFunc = Hash())
      : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {
   }
   ```

   The constructor initializes the hash table's size, hash function, bucket array, and element count.  If no initial size and hash function are provided, it uses default values. The constructor initializes the bucket array based on the provided size.

4. `insert` Method:

   ```cpp
   void insert(const Key &key, const Value &value) {
       if ((numElements + 1) > maxLoadFactor * tableSize) { // Checks if rehashing is needed.
         // Handles the case where tableSize is 0 after a clear operation and subsequent insertion.
         if (tableSize == 0) tableSize = 1;
         rehash(tableSize * 2); // Rehashes, doubling the number of buckets.
       }
       size_t index = hash(key);                     // Calculates the index of the key.
       std::list<HashNode> &bucket = buckets[index]; // Gets the corresponding bucket.
       // If the key is not in the bucket, add it to the bucket.
       if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
         bucket.push_back(HashNode(key, value));
         ++numElements; // Increases the number of elements.
       }
   }
   ```

   Inserts a new key-value pair. It first checks if rehashing is necessary; if so, it performs rehashing. Then, it calculates the key's hash value to find the corresponding bucket. If the key doesn't already exist in the bucket, it's added to the end of the bucket's linked list, and the element count is incremented.

5. `erase` Method:

   ```cpp
   void erase(const Key &key) {
       size_t index = hash(key);      // Calculates the index of the key.
       auto &bucket = buckets[index]; // Gets the corresponding bucket.
       auto it = std::find(bucket.begin(), bucket.end(), key); // Finds the key.
       if (it != bucket.end()) {                               // If the key is found.
           bucket.erase(it); // Removes the key from the bucket.
           numElements--;    // Decreases the number of elements.
       }
   }
   ```

   Removes a key. It calculates the key's hash value, finds the corresponding bucket, and iterates through the bucket to find the key. If found, it removes the key and decrements the element count.

6. `find` Method:

   ```cpp
   Value *find(const Key &key) {
       size_t index = hash(key);      // Calculates the index of the key.
       auto &bucket = buckets[index]; // Gets the corresponding bucket.
       // Returns whether the key is in the bucket.
       auto ans = std::find(bucket.begin(), bucket.end(), key);
       if (ans != bucket.end()) {
         return &ans->value;
       };
       return nullptr;
   }
   ```

   Checks if a key exists in the hash table. It calculates the key's hash value, finds the corresponding bucket, and uses `std::find` to search for the key within the bucket. If found, it returns a pointer to the value; otherwise, it returns a null pointer.

7. `size` Method:

   ```cpp
   size_t size() const { return numElements; }
   ```

   Simply returns the current number of elements in the hash table.

8. `print` Method:

   ```cpp
   void print() const {
       for (size_t i = 0; i < buckets.size(); ++i) {
         for (const HashNode &element : buckets[i]) {
           element.print();
         }
       }
       std::cout << std::endl;
   }
   ```

   Prints all keys in the hash table. It iterates through all buckets and prints all elements within each bucket.

Collision resolution in this hash table implementation is done using separate chaining (using linked lists within buckets). When a key's hash value maps to a bucket already containing other keys, the new key is added to the linked list associated with that bucket.

Note that in the `HashTable` constructor, the `buckets` array is initialized twice: once in the member initializer list and again in the constructor body.  This is redundant and the initialization in the constructor body is unnecessary.
