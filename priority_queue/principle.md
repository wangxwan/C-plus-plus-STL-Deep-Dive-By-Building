# How Heaps Work

A heap is a specialized complete binary tree that satisfies the following properties:

1. **Structural Property:** A heap is a complete binary tree. This means that all levels are completely filled except possibly the last level, and the nodes in the last level are as far left as possible.
2. **Heap Property:** In a max-heap, the value of each node is greater than or equal to the value of its children, and the root node contains the maximum value in the heap. Conversely, in a min-heap, the value of each node is less than or equal to the value of its children, and the root node contains the minimum value in the heap.


## Heap Insertion and Deletion:

- **Insertion:** When inserting a new element, the new element is first placed at the last position of the tree to maintain the complete binary tree structure. Then, the element "bubbles up" (or "heapifies up") by comparing itself with its parent and swapping positions (if the new element is larger than its parent in a max-heap, or smaller in a min-heap). This process repeats until the new element reaches a position where it is no longer larger (or smaller) than its parent, or it reaches the top of the tree.
- **Deletion:** In a heap, deletion usually refers to deleting the root node, which contains the maximum (or minimum) element. After deletion, the structural property of the heap must be maintained. This is typically done by moving the last element to the root node position, and then performing a "bubble down" (or "heapifies down") process. The element is compared with its children and swapped with the larger (or smaller) child as needed. This process continues until the element is in its correct position, or it reaches the bottom of the tree.
- **Heapify:** The process of building a heap from an unsorted array is called heapify. This can be done by starting from the last non-leaf node and performing a bubble-down operation on each node. In an array representation, given an element at index `i`, its left child is at index `2*i + 1`, its right child is at index `2*i + 2`, and its parent is at index `(i-1)/2`.