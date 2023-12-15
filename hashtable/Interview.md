# Common Hash Table Interview Questions

1. **What is a hash table? How does it work?**
   - Answer: A hash table is a data structure that uses a hash function to organize data for fast insertion and search. It stores key-value pairs by mapping keys to locations in the table. The hash function converts each key into an index in the hash table, which determines where the key-value pair is stored. If two keys map to the same index, a collision occurs, typically resolved using linked lists or open addressing.

2. **What is a hash collision? How are hash collisions handled?**
   - Answer: A hash collision occurs when different keys map to the same location in the hash table via the hash function. Methods for handling hash collisions include:
     - **Separate Chaining (Linked List Method):** Maintains a linked list at each hash table index; all elements mapping to that index are stored in the list.
     - **Open Addressing:** If a collision occurs, the next available hash table index is searched.
     - **Double Hashing:** Uses a series of hash functions instead of a single one to determine the element's storage location.

3. **How to choose a good hash function?**
   - Answer: A good hash function should meet the following criteria:
     - Fast computation.
     - Uniform distribution of hash values to minimize collisions.
     - Deterministic: The same input always produces the same output.
     - Different inputs should map to different outputs as much as possible.

4. **What is a load factor? What is its impact on a hash table?**
   - Answer: The load factor is the ratio of the number of elements stored in a hash table to the total number of slots. It's a measure of how full the hash table is. When the load factor is too high, the probability of collisions increases, degrading hash table performance.  Therefore, hash tables typically resize (rehash) when the load factor reaches a certain threshold, increasing the number of slots to reduce collisions and maintain efficient operations.

5. **Explain rehashing. When and why is rehashing needed?**
   - Answer: Rehashing is the process of increasing the capacity of a hash table and redistributing existing elements when the load factor exceeds a predetermined threshold. This involves calculating new hash values for each element and moving them to the correct locations in the new table. Rehashing helps reduce collisions and maintain fast operation performance.

6. **What is the complexity of insertion, deletion, and search operations in a hash table?**
   - Answer: Ideally, with no or very few collisions, insertion, deletion, and search operations have a time complexity of O(1). However, in the worst case, if all keys map to the same index, the time complexity degrades to O(n), where n is the number of elements in the hash table. Using a good hash function and collision resolution strategy helps maintain an average time complexity close to O(1).

7. **How to address the resizing problem in hash tables?**
   - Answer: Resizing typically occurs when the hash table's load factor exceeds a predefined threshold. Solutions generally involve:
     - **Creating a larger hash table:** Creating a new hash table with a larger capacity.
     - **Rehashing all elements:** Recalculating the hash values of all existing elements and inserting them into the new hash table.
     - **Incremental migration:** In some implementations, elements can be incrementally migrated to the new table, spreading the rehashing cost over multiple insertion operations.

8. **How to ensure thread safety for a hash table?**
   - Answer: Ensuring thread safety for a hash table can be achieved through one of the following:
     - **Mutexes:** Using mutexes to synchronize access to the hash table. Each thread accessing the hash table needs to acquire the lock first.
     - **Readers-writer locks:** If read operations far outnumber write operations, using readers-writer locks can improve performance as it allows multiple threads to read concurrently but requires exclusive access for writing.
     - **Atomic operations:** For simple operations, atomic operations can be used to avoid using locks.
     - **Fine-grained locking:** Instead of locking the entire hash table, locking a portion of the hash table (e.g., individual buckets or linked lists) can reduce lock granularity.

9. **What are some common hash table implementation issues?**
   - Answer: Common hash table implementation issues include:
     - **Inefficient memory usage:**  A hash table that is too large or has many empty buckets can lead to memory waste.
     - **Poor collision handling:** Ineffective collision handling severely impacts hash table performance.
     - **Poor hash function choice:** A bad hash function can lead to frequent collisions.
     - **High cost of resizing:** Rehashing is a costly operation; if it happens too frequently, it can significantly impact performance.