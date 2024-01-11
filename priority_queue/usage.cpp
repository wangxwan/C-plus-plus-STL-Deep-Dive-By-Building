#include <iostream>
#include <vector>
#include <algorithm> // for std::make_heap, std::push_heap, std::pop_heap

template <typename T, typename Container = std::vector<T>>
class MyPriorityQueue {
private:
    Container data; // Underlying container to store priority queue elements

public:
    // Default constructor
    MyPriorityQueue() {}

    // Constructor, allows specifying the underlying container
    MyPriorityQueue(const Container& c) : data(c) {
        std::make_heap(data.begin(), data.end());
    }

    // Add an element to the priority queue
    void push(const T& value) {
        data.push_back(value);
        std::push_heap(data.begin(), data.end());
    }

    // Remove the largest element from the priority queue
    void pop() {
        if (!empty()) {
            std::pop_heap(data.begin(), data.end());
            data.pop_back();
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    // Access the largest element in the priority queue
    T& top() {
        if (!empty()) {
            return data.front();
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    // Check if the priority queue is empty
    bool empty() const {
        return data.empty();
    }

    // Return the size of the priority queue
    size_t size() const {
        return data.size();
    }
};

int main() {
    // Example using the default underlying container (std::vector)
    MyPriorityQueue<int> pq1;

    pq1.push(3);
    pq1.push(1);
    pq1.push(4);
    pq1.push(1);

    std::cout << "Top element of pq1: " << pq1.top() << std::endl;

    pq1.pop();
    std::cout << "Priority queue pq1 size after pop: " << pq1.size() << std::endl;

    // Example using std::vector as the underlying container
    std::vector<int> vec = {9, 5, 7, 2, 6};
    MyPriorityQueue<int, std::vector<int>> pq2(vec);

    std::cout << "Top element of pq2: " << pq2.top() << std::endl;

    pq2.pop();
    std::cout << "Priority queue pq2 size after pop: " << pq2.size() << std::endl;

    return 0;
}