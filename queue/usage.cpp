#include <iostream>
#include <queue>

int main() {
    std::queue<int> q; // Create an empty queue of integers

    // Enqueue operations
    q.push(10); // Add 10 to the queue
    q.push(20); // Add 20 to the queue
    q.push(30); // Add 30 to the queue

    // Accessing the front and back elements
    std::cout << "Front element is: " << q.front() << std::endl; // Output: 10
    std::cout << "Back element is: " << q.back() << std::endl;  // Output: 30

    // Dequeue operation
    std::cout << "Performing dequeue operation..." << std::endl;
    q.pop(); // Remove the front element (10)

    // Accessing the front element again
    std::cout << "Now the front element is: " << q.front() << std::endl; // Output: 20

    // Traversing the queue (Note: Standard queue doesn't provide direct iteration, this is for demonstration)
    std::cout << "Elements in the queue: ";
    while (!q.empty()) { // Check if the queue is empty
        std::cout << q.front() << " "; // Output the front element
        q.pop(); // Remove the front element
    }
    std::cout << std::endl;

    return 0;
}