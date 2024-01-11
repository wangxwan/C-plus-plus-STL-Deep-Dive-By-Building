#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T, typename Container = std::vector<T>>
class MyPriorityQueue {
private:
    Container data;

    // Helper function: Adjusts element upwards to maintain heap property
    void heapifyUp() {
        int index = data.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (data[index] > data[parentIndex]) {
                std::swap(data[index], data[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Helper function: Adjusts element downwards to maintain heap property
    void heapifyDown() {
        int index = 0;
        int size = data.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && data[leftChild] > data[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && data[rightChild] > data[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                std::swap(data[index], data[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    MyPriorityQueue() {}

    MyPriorityQueue(const Container& c) : data(c) {
        // Convert underlying container to a heap
        int size = data.size();
        for (int i = (size / 2) - 1; i >= 0; --i) {
            heapifyDown();
        }
    }

    void push(const T& value) {
        data.push_back(value);
        heapifyUp();
    }

    void pop() {
        if (!empty()) {
            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            heapifyDown();
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    T& top() {
        if (!empty()) {
            return data[0];
        } else {
            throw std::runtime_error("Priority queue is empty.");
        }
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    // Using std::vector as the underlying container
    MyPriorityQueue<int, std::vector<int>> myPriorityQueue;

    int N;
    std::cin >> N;
    getchar();

    std::string line;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int element;

        if (command == "push") {
            iss >> element;
            myPriorityQueue.push(element);
        }

        if (command == "pop") {
            try {
                myPriorityQueue.pop();
            } catch(const std::runtime_error& e) {
                // Do nothing
                continue;
            }
        }

        if (command == "top") {
            try {
                std::cout << myPriorityQueue.top() << std::endl;
            } catch(const std::runtime_error& e) {
                std::cout << "null" << std::endl;
            }   
        }

        if (command == "size") {
            std::cout << myPriorityQueue.size() << std::endl;
        }

        if (command == "empty") {
            std::cout << (myPriorityQueue.empty() ? "true" : "false") << std::endl;
        }
    }
    return 0;
}