# High-Frequency Interview Questions

#### Interview Question 1: What are the main differences between `deque` and `vector`?

**Answer:**

- **Memory Allocation:** `vector` uses a single contiguous block of memory to store elements, while `deque` uses multiple, potentially discontiguous blocks of memory. This means `deque` can efficiently insert and delete elements at both ends, whereas `vector` is only efficient for these operations at the end.
- **Insertion Efficiency:** Inserting or deleting elements at the front and back of a `deque` is highly efficient, but inserting or deleting in the middle is less efficient because it may require moving elements across multiple memory blocks.  `vector` is efficient for insertion and deletion at the end, but less efficient at the front or middle because it may require shifting many elements.
- **Random Access:** `vector` offers faster random access because of its contiguous memory layout, while `deque` has slightly slower random access due to its discontiguous memory blocks.
- **Memory Overhead:** `vector` can have a significant memory reallocation cost when expanding, while `deque`, due to its segmented storage, typically avoids large memory reallocations.


#### Interview Question 2: Can a `deque` be used to implement a fixed-size sliding window? If so, how?

**Answer:** Yes, a `deque` can be used to implement a fixed-size sliding window. Here's a simple example:

```cpp
#include <iostream>
#include <deque>

void slidingWindowMaximum(const std::vector<int>& nums, int k) {
    std::deque<int> window;

    for (size_t i = 0; i < nums.size(); ++i) {
        // Remove elements outside the left boundary of the window.
        if (!window.empty() && window.front() == i - k) {
            window.pop_front();
        }

        // Maintain decreasing order in the deque.
        while (!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }

        // Add the index of the current element.
        window.push_back(i);

        // Output the maximum value from the window's start.
        if (i >= k - 1) {
            std::cout << nums[window.front()] << " ";
        }
    }
    std::cout << std::endl;
}
```

This function takes an integer array `nums` and an integer `k` as the window size, and then prints the maximum value in each sliding window.


#### Interview Question 3: What happens to iterators when an element is inserted at the front of a `deque`?

**Answer:** In the C++ STL, for `std::deque`, inserting an element at the front typically invalidates all iterators, references, and pointers. This is because the `deque` might internally reallocate, especially if there isn't enough space at the front to accommodate the new element. This is different from `std::vector`, where iterators remain valid when inserting at the end.


#### Interview Question 4: What is the difference between using the `[]` operator and the `at()` method in a `deque`?

**Answer:**

- `operator[]` provides unchecked access to elements. This means that if an out-of-bounds index is used, it doesn't throw an exception but leads to undefined behavior.
- `at()` provides bounds-checked access. If the specified index is out of the `deque`'s range, the `at()` method throws a `std::out_of_range` exception. Therefore, `at()` is safer than `operator[]` but might be slightly less performant.

Using `at()` can help catch out-of-bounds errors during debugging, while `operator[]` can offer better performance when you're certain that you won't go out of bounds.


#### Interview Question 5: Explain the internal workings of a `deque`. How does it achieve efficient insertion and deletion at both ends?

**Answer:** `std::deque` maintains a series of fixed-size arrays (called blocks or buffers) and a central controller (usually an array of pointers) to manage these blocks. Each block can grow and shrink independently, meaning that when adding or removing elements at either end, only the relevant block(s) are affected.

- **Insertion at the front:** If the first block has space, the new element is inserted at the beginning of that block. If there's no space, the `deque` allocates a new block and links it to the existing sequence of blocks.
- **Insertion at the back:** If the last block has space, the new element is inserted at the end of that block. If there's no space, the `deque` allocates a new block and links it to the existing sequence of blocks.
- **Deletion at the front:** The first element of the first block is removed. If the block becomes empty, its resources are released, and the central controller is updated.
- **Deletion at the back:** The last element of the last block is removed. If the block becomes empty, its resources are released, and the central controller is updated.

In this way, `deque` can efficiently insert and delete at both ends without needing to shift elements except at the point of operation, which is necessary in a `vector`.


#### Interview Question 6: How many constructors does `deque` have, and what are they used for?

**Answer:** `std::deque` provides several constructors, allowing for different ways to create `deque` objects:

1. **Default constructor:** Creates an empty `deque`.

   ```cpp
   std::deque<int> dq;
   ```

2. **Fill constructor:** Creates a `deque` with a given number of elements, each a copy of a given initial value.

   ```cpp
   std::deque<int> dq(10, 5); // 10 elements, each is 5
   ```

3. **Range constructor:** Creates a new `deque` copying elements from a given iterator range.

   ```cpp
   std::vector<int> vec{1, 2, 3, 4, 5};
   std::deque<int> dq(vec.begin(), vec.end());
   ```

4. **Copy constructor:** Creates a new `deque` as a copy of another `deque`.

   ```cpp
   std::deque<int> dq1(10, 5);
   std::deque<int> dq2(dq1); // Copy of dq1
   ```

5. **Move constructor** (C++11 introduced): Moves elements from another `deque`, typically involving moving internal pointers rather than copying elements.

   ```cpp
   std::deque<int> dq1(10, 5);
   std::deque<int> dq2(std::move(dq1)); // Moves from dq1
   ```

6. **Initializer list constructor** (C++11 introduced): Creates a `deque` using an initializer list.

   ```cpp
   std::deque<int> dq{1, 2, 3, 4, 5};
   ```

7. **Default constructor with allocator:** Creates an empty `deque` using a custom allocator for memory management.  Similar variations exist for fill, range, copy, and move constructors, and the initializer list constructor.  These are all analogous to the examples above, but with an additional `std::allocator` argument.