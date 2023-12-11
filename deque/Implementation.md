# Implementing a Deque

This implementation uses a dynamic array and pointers to achieve basic deque operations.  Adding and removing elements from both the front and back of the deque are simulated using array indices.

First, here's [the complete basic implementation code](Implementation.cpp)

1. `push_front`:

   ```cpp
   void push_front(const T& value) {
        // Checks if resizing is needed.
        if (size == capacity) {
            resize();
        }
   
        // Calculates the new front index.
        frontIndex = (frontIndex - 1 + capacity) % capacity;
   
        // Inserts the element at the new front position.
        elements[frontIndex] = value;
   
        // Increments the deque size.
        ++size;
    }
   ```

   Inserts an element at the front of the queue.  It first checks the capacity and resizes the array (if necessary). Then, it updates `frontIndex` to point to the new front position, inserts the element, and finally increments `size`.  `frontIndex = (frontIndex - 1 + capacity) % capacity;` prevents negative array indices, wrapping around to the end of the array.

2. `push_back`:

   ```cpp
   void push_back(const T& value) {
        // Checks if resizing is needed.
        if (size == capacity) {
            resize();
        }
   
        // Inserts the element at the current back position.
        elements[backIndex] = value;
   
        // Calculates the new back index.
        backIndex = (backIndex + 1) % capacity;
   
        // Increments the deque size.
        ++size;
    }
   ```

   Inserts an element at the back of the queue.  Similar to `push_front`, it checks capacity, resizes if needed, inserts the element at `backIndex`, updates `backIndex` (wrapping around using the modulo operator), and increments `size`. `backIndex = (backIndex + 1) % capacity;` prevents index out-of-bounds, wrapping around to the beginning of the array.

3. `pop_front`:

   ```cpp
   void pop_front() {
        // Checks if the deque is empty.
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
   
        // Explicit deletion isn't necessary; new elements will overwrite.
        // Calculates the new front index.
        frontIndex = (frontIndex + 1) % capacity;
   
        // Decrements the deque size.
        --size;
    }
   ```

   Removes an element from the front of the queue. It first checks for emptiness, then updates `frontIndex`, and finally decrements `size`.

4. `pop_back`:

   ```cpp
   void pop_back() {
        // Checks if the deque is empty.
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
   
        // Explicit deletion isn't necessary; new elements will overwrite.
        // Calculates the new back index.
        backIndex = (backIndex - 1 + capacity) % capacity;
   
        // Decrements the deque size.
        --size;
    }
   ```

   Removes an element from the back of the queue.  Similar to `pop_front`, it checks for emptiness, updates `backIndex`, and decrements `size`.

5. `operator[]`:

   ```cpp
   T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }
   
    // Returns the number of elements in the deque.
    size_t getSize() const {
        return size;
    }
   ```

   Provides random access to elements using the `[]` operator.  It calculates the actual array index based on the given logical index and the `frontIndex` offset.  This uses a logical index, starting from `frontIndex`, rather than the raw array index.

6. `getSize`:

   ```cpp
    size_t getSize() const {
        return size;
    }
   ```

   Returns the number of elements in the deque.

7. `clear`:

   ```cpp
   void clear() {
        while (size > 0) {
            pop_front();
        }
    }
   ```

   Clears all elements from the deque by repeatedly calling `pop_front`.

8. `printElements`:

   ```cpp
    void printElements() const {
        size_t index = frontIndex;
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[index] << " ";
            index = (index + 1) % capacity;
        }
        std::cout << std::endl;
    }
   ```

   Prints all elements in the deque, iterating from `frontIndex` until all elements are printed.  `index` here is a logical index, starting from `frontIndex`.

9. `resize`:

   ```cpp
   void resize() {
       // Calculates the new capacity.
       size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
   
       // Creates a new array.
       T* newElements = new T[newCapacity];
   
       // Copies elements to the new array.
       size_t index = frontIndex;
       for (size_t i = 0; i < size; ++i) {
           newElements[i] = elements[index];
           index = (index + 1) % capacity;
       }
   
       // Releases memory of the old array.
       delete[] elements;
   
       // Updates member variables.
       elements = newElements;
       capacity = newCapacity;
       frontIndex = 0;
       backIndex = size;
   }
   ```

   When the array capacity is insufficient, it creates a new array, copies existing elements, releases the old array, and updates member variables.  Note that the logical index 0 (i.e., `frontIndex`) in the original array doesn't necessarily reside at the actual index 0. However, `resize` aligns the logical and physical indices after resizing.

This `Deque` implementation is based on a dynamic array, allowing efficient insertion and deletion at both ends, along with random access in the middle. Note that this implementation doesn't provide iterators, nor does it implement some potentially useful functions like `front`, `back`, `empty`, and a constructor to support a custom initial capacity.  Furthermore, the `resize` function has linear time complexity for copying elements, but due to the doubling strategy, the amortized complexity of `push_front` and `push_back` remains constant.