# High-Frequency Interview Questions

1. **How to find the Kth largest element from a given unsorted array?**

   You can use a min-heap to solve this problem. The steps are as follows:

   - Create a min-heap of size K.
   - Iterate through the array, adding the first K elements to the heap.
   - For the remaining elements, if an element is greater than the top element of the heap, replace the top element with this element and re-heapify.
   - Finally, the top element of the heap is the Kth largest element.

   *Time Complexity: `O(n log k)`*


2. **Implement a priority queue and explain the time complexity of its insertion and deletion operations.**

   Priority queues are typically implemented using a heap data structure.

   - **Insertion:** Add the new element to the end of the heap, then bubble it up to its correct position.
   - **Deletion:** Remove the top element (highest priority), move the last element to the top, then bubble it down to its correct position.

   *Time Complexity: Both insertion and deletion operations are `O(log n)`.*


3. **What is heapsort? What are its time and space complexities?**

   Heapsort is a sorting algorithm that uses a heap data structure.

   - Build a max-heap from the unsorted array.
   - Repeatedly remove the maximum element from the heap and place it at the end of the array.

   *Time Complexity: `O(n log n)`*  *Space Complexity: `O(1)` (in-place sorting)*


4. **What are the differences between a binary heap and a Fibonacci heap? How do their operation time complexities differ?**

   Binary heaps and Fibonacci heaps are different types of heaps, primarily distinguished by their operation time complexities.

   - **Binary Heap:** Insertion and deletion operations have a time complexity of `O(log n)`.
   - **Fibonacci Heap:**  Insertion and decrease-key operations have a time complexity of `O(1)`, and delete-min has a time complexity of `O(log n)`, but these are amortized time complexities.  The actual time for a single operation can be higher, but the average time over many operations is guaranteed.


5. **How to build a heap in O(n) time complexity?**

   Building a heap can be done as follows:

   - Start from the last non-leaf node and perform a heapify-down operation.
   - Repeat the above step until the root node is processed.

   *Time Complexity: `O(n)`*


6. **Explain the heapsort algorithm and its time complexity.**

   The heapsort algorithm involves these steps:

   - Build a max-heap.
   - Swap the root (maximum) element with the last element, then reduce the heap size.
   - Re-heapify the new root element.
   - Repeat until the heap size is 1.

   *Time Complexity: `O(n log n)`*


7. **Given a k-sorted array, how to sort it in optimal time complexity?**

   For a k-sorted array (an array where each element is at most k positions away from its sorted position), you can use a min-heap:

   - Create a min-heap of size `k + 1` and add the first `k + 1` elements.
   - Iterate through the array from position `k + 1`.  For each element: remove the minimum element from the heap and place it in the sorted output array; then add the current element from the input array to the heap.
   - After iterating through the input array, the remaining elements in the heap are added to the sorted output array.

   *Time Complexity: `O(n log k)`*  