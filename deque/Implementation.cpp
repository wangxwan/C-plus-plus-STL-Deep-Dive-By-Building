#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
class Deque {
private:
    T* elements;  // A circular one-dimensional array.
    size_t capacity;  // The total capacity of the array.
    size_t frontIndex;  // The index of the front of the deque.
    size_t backIndex;  // The index of the back of the deque.
    size_t size;  // The number of elements in the deque.

public:
    // Constructor
    Deque() : elements(nullptr), capacity(0), frontIndex(0), backIndex(0), size(0) {}

    // Destructor
    ~Deque() {
        clear();
        delete[] elements;
    }

    // Inserts an element at the front of the deque.
    void push_front(const T& value) {
        // Checks if the array needs to be resized.
        if (size == capacity) {
            resize();
        }

        // Calculates the new front index.
        frontIndex = (frontIndex - 1 + capacity) % capacity;

        // Inserts the element at the new front position.
        elements[frontIndex] = value;

        // Increments the number of elements in the deque.
        ++size;
    }

    // Inserts an element at the back of the deque.
    void push_back(const T& value) {
        // Checks if the array needs to be resized.
        if (size == capacity) {
            resize();
        }

        // Inserts the element at the current back position.
        elements[backIndex] = value;

        // Calculates the new back index.
        backIndex = (backIndex + 1) % capacity;

        // Increments the number of elements in the deque.
        ++size;
    }

    // Removes the element from the front of the deque.
    void pop_front() {
        // Checks if the deque is empty.
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }

        // Explicit deletion is not needed; new elements will overwrite.
        // Calculates the new front index.
        frontIndex = (frontIndex + 1) % capacity;

        // Decrements the number of elements in the deque.
        --size;
    }

    // Removes the element from the back of the deque.
    void pop_back() {
        // Checks if the deque is empty.
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }

        // Explicit deletion is not needed; new elements will overwrite.
        // Calculates the new back index.
        backIndex = (backIndex - 1 + capacity) % capacity;

        // Decrements the number of elements in the deque.
        --size;
    }
    // Provides random access to elements using the [] operator.
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[(frontIndex + index) % capacity];
    }

    // Returns the number of elements in the deque.
    size_t getSize() const {
        return size;
    }

    // Clears the deque.
    void clear() {
        while (size > 0) {
            pop_front();
        }
    }

    // Prints the elements of the deque.
    void printElements() const {
        size_t index = frontIndex;
        for (size_t i = 0; i < size; ++i) {
            std::cout << elements[index] << " ";
            index = (index + 1) % capacity;
        }
        std::cout << std::endl;
    }

private:
    // Resizes the array capacity.
    void resize() {
        // Calculates the new capacity.
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;

        // Creates a new array.
        T* newElements = new T[newCapacity];

        // Copies elements to the new array.
        size_t index = frontIndex;
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[index];
            index = (index + 1) % capacity;
        }

        // Releases memory of the old array.
        delete[] elements;

        // Updates member variables.
        elements = newElements;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = size;
    }
};

int main() {
    // Creates a Deque object.
    Deque<int> myDeque;

    int N;
    std::cin >> N;
    // Consumes the newline character after reading N.
    getchar();
    std::string line;
    // Receives commands.
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        // Processes commands.
        if (command == "push_back") {
            iss >> value;
            myDeque.push_back(value);
        } else if (command == "push_front") {
            iss >> value;
            myDeque.push_front(value);
        } else if (command == "pop_back") {
            if (myDeque.getSize() > 0) {
                myDeque.pop_back();
            }
        } else if (command == "pop_front") {
            if (myDeque.getSize() > 0) {
                myDeque.pop_front();
            }
        } else if (command == "clear") {
            myDeque.clear();
        } else if (command == "size") {
            std::cout << myDeque.getSize() << std::endl;
        } else if (command == "get") {
            iss >> value;
            std::cout << myDeque[value] << std::endl;
        } else if (command == "print") {
            if (myDeque.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myDeque.printElements();
            }
        }
    }
    return 0;
}