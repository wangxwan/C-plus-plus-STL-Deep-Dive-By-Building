
# Multiset

A `multiset` is an ordered container that allows duplicate elements and stores them in a sorted order based on their values.

Internally, a `multiset` is typically implemented using a red-black tree, a self-balancing binary search tree.  The properties of a red-black tree ensure the tree remains balanced during dynamic operations, resulting in relatively low time complexity for various operations.

## Multiset Characteristics

1. **Ordered:** Elements in a `multiset` are ordered in ascending order based on their values. This allows for easy ordered access to elements.
2. **Allows Duplicates:** Unlike a `set`, a `multiset` allows storing the same element multiple times.  This means you can store multiple elements with the same value, and they will remain ordered after sorting.
3. **Red-Black Tree Based:**  A `multiset` is typically implemented using a red-black tree. This self-balancing binary search tree ensures efficient performance for insertion, deletion, and search operations.

## Multiset Performance Considerations

1. **Insertion and Deletion Performance:** Because `multiset` uses a red-black tree internally, the performance of inserting and deleting elements is generally good, with an average time complexity of O(log n).
2. **Search Performance:** The ordered nature of the red-black tree also results in good search performance, with an average time complexity of O(log n).
3. **Memory Overhead:** The internal implementation of a `multiset` typically requires extra memory to store the red-black tree nodes, resulting in potentially higher memory overhead compared to some other containers.
4. **Use Cases:** `multiset` is suitable for scenarios requiring ordered storage of elements that allow duplicates, such as maintaining a collection of events sorted by timestamp.


## Basic Usage of `multiset` in the C++ Standard Library

[Usage](usage.cpp)


## How `multiset` Works

In a `multiset`, to store duplicate elements, each node in the red-black tree contains a key and a counter representing the number of times that key appears in the `multiset`.

When inserting an element, if the key already exists in the red-black tree, the counter is incremented; otherwise, a new node is inserted, and the counter is initialized to 1.

When deleting an element, if the counter is greater than 1, it's decremented; if it's equal to 1, the node is removed from the red-black tree.

When searching for an element, the red-black tree's search operation finds the node containing the key and returns the counter value.


## Implementing `multiset`

Based on a previously implemented `RedBlackTree` (assuming its class definition and implementation are in `RedBlackTree.h`):

[Detail](Implementation.md)

