#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept> // For exception handling
#include <sstream>
#include <string>

template <typename T, typename Container = std::deque<T>>
class MyStack {
private:
    Container data; // Uses the underlying container to store stack elements

public:
    // Pushes an element onto the top of the stack
    void push(const T& value) {
        data.push_back(value);
    }

    // Pops the top element from the stack
    void pop() {
        if (!empty()) {
            data.pop_back();
        } else {
            throw std::runtime_error("Stack is empty.");
        }
    }

    // Returns a reference to the top element
    T& top() {
        if (!empty()) {
            return data.back();
        } else {
            throw std::runtime_error("Stack is empty.");
        }
    }

    // Checks if the stack is empty
    bool empty() const {
        return data.empty();
    }

    // Returns the size of the stack
    size_t size() const {
        return data.size();
    }
};

int main() {
    // Example using std::deque as the underlying container
    MyStack<int, std::deque<int>> stack;

    int N;
    std::cin >> N;
    getchar(); // Consume the newline character after reading N

    std::string line;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int element;
        if (command == "push") {
            iss >> element;
            stack.push(element);
        } else if (command == "pop") {
            try {
                stack.pop();
            } catch (const std::runtime_error& e) {
                // Do nothing
                continue;
            }
        } else if (command == "top") {
            try {
                std::cout << stack.top() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << "null" << std::endl;
            }
        } else if (command == "size") {
            std::cout << stack.size() << std::endl;
        } else if (command == "empty") {
            std::cout << (stack.empty() ? "true" : "false") << std::endl;
        }
    }
    return 0;
}