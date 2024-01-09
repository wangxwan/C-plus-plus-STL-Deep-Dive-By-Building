#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <stdexcept> // For exception handling
#include <sstream>
#include <string>

template <typename T, typename Container = std::deque<T>>
class MyQueue {
private:
    Container data; // Uses an underlying container to store queue elements

public:
    // Adds an element to the back of the queue
    void push(const T& value) {
        data.push_back(value);
    }

    // Removes the element at the front of the queue
    void pop() {
        if (!empty()) {
            data.pop_front();
        } else {
            throw std::runtime_error("Queue is empty.");
        }
    }

    // Accesses a reference to the element at the front of the queue
    T& front() {
        if (!empty()) {
            return data.front();
        } else {
            throw std::runtime_error("Queue is empty.");
        }
    }

    // Accesses a reference to the element at the back of the queue
    T& back() {
        if (!empty()) {
            return data.back();
        } else {
            throw std::runtime_error("Queue is empty.");
        }
    }

    // Checks if the queue is empty
    bool empty() const {
        return data.empty();
    }

    // Returns the size of the queue
    size_t size() const {
        return data.size();
    }
};

int main() {
    // Example using std::deque as the underlying container
    MyQueue<int, std::deque<int>> myQueue;

    int N;
    std::cin >> N;
    std::cin.ignore(); // Consume the newline character left by std::cin >> N
    std::string line;

    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int element;

        if (command == "push") {
            iss >> element;
            myQueue.push(element);
        } else if (command == "pop") {
            try {
                myQueue.pop();
            } catch (const std::runtime_error& e) {
                // Do nothing
                continue;
            }
        } else if (command == "front") {
            try {
                std::cout << myQueue.front() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "null" << std::endl;
            }
        } else if (command == "back") {
            try {
                std::cout << myQueue.back() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "null" << std::endl;
            }
        } else if (command == "size") {
            std::cout << myQueue.size() << std::endl;
        } else if (command == "empty") {
            std::cout << (myQueue.empty() ? "true" : "false") << std::endl;
        }
    }
    return 0;
}