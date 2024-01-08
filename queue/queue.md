# Queue

`std::queue` is a container adapter in the C++ Standard Template Library (STL) that provides queue functionality (FIFO, First-In, First-Out).

A queue is a First-In, First-Out (FIFO) data structure, meaning the element that was added first will be the first one removed.  Think of a line at a ticket counter; the first person in line is the first person served and leaves the line.

## Features

- **First-In, First-Out (FIFO):**  Similar to a real-world queue, elements in `std::queue` are arranged in a sequential order, with the first element added being the first element removed.
- **Encapsulation:** `std::queue` provides encapsulation over an underlying container. By default, `std::queue` uses `std::deque` as its underlying container, but it can be configured to use `std::list` or other suitable containers.
- **Simple Interface:** `std::queue` offers a simple interface for adding, removing, and accessing the front and back elements of the queue.

## Performance

**Time Complexity:** Enqueue (push) and dequeue (pop) operations are typically constant time O(1), meaning the time taken for these operations doesn't significantly increase with the size of the queue.

**Space Complexity:** Since `std::queue` uses an underlying container to store elements, its space complexity depends on the underlying container used.

For example, when using `std::deque`, the space complexity is generally linear O(n), where n is the number of elements in the queue.