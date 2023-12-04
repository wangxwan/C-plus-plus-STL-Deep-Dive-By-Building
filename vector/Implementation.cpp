#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <string>  
#include <stdexcept>  

template <typename T>  
class Vector  
{  
private:  
    T *elements;     // Pointer to the dynamic array  
    size_t capacity; // Capacity of the array  
    size_t size;     // Number of elements in the array  

public:  
    // Constructor  
    Vector() : elements(nullptr), capacity(0), size(0) {}  

    // Destructor  
    ~Vector()  
    {  
        delete[] elements;  
    }  

    // Copy constructor  
    Vector(const Vector &other) : capacity(other.capacity), size(other.size)  
    {  
        elements = new T[capacity];  
        std::copy(other.elements, other.elements + size, elements);  
    }  

    // Copy assignment operator  
    Vector &operator=(const Vector &other)  
    {  
        if (this != &other)  
        {  
            delete[] elements;  
            capacity = other.capacity;  
            size = other.size;  
            elements = new T[capacity];  
            std::copy(other.elements, other.elements + size, elements);  
        }  
        return *this;  
    }  

    // Add an element to the end of the array  
    void push_back(const T &value)  
    {  
        if (size == capacity)  
        {  
            // If the array is full, increase the capacity  
            reserve(capacity == 0 ? 1 : 2 * capacity);  
        }  
        elements[size++] = value;  
    }  

    // Retrieve the number of elements in the array  
    size_t getSize() const  
    {  
        return size;  
    }  

    // Retrieve the capacity of the array  
    size_t getCapacity() const  
    {  
        return capacity;  
    }  

    // Access an element in the array  
    T &operator[](size_t index)  
    {  
        // Check index for out of range  
        if (index >= size)  
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return elements[index];  
    }  

    // const version of accessing an element in the array  
    const T &operator[](size_t index) const  
    {  
        // Check index for out of range  
        if (index >= size)  
        {  
            throw std::out_of_range("Index out of range");  
        }  
        return elements[index];  
    }  

    // Insert an element at a specified position  
    void insert(size_t index, const T &value)  
    {  
        if (index > size)  
        {  
            throw std::out_of_range("Index out of range");  
        }  
        if (size == capacity)  
        {  
            reserve(capacity == 0 ? 1 : capacity * 2);  
        }  
        for (size_t i = size; i > index; --i)  
        {  
            elements[i] = elements[i - 1];  
        }  
        elements[index] = value;  
        ++size;  
    }  

    // Remove the last element of the array  
    void pop_back()  
    {  
        if (size > 0)  
        {  
            --size;  
        }  
    }  

    // Clear the array  
    void clear()  
    {  
        size = 0;  
    }  

    // Begin iterator for traversing the array  
    T *begin()  
    {  
        return elements;  
    }  

    // End iterator for traversing the array  
    T *end()  
    {  
        return elements + size;  
    }  

    // Begin iterator for traversing the array (const version)  
    const T *begin() const  
    {  
        return elements;  
    }  

    // End iterator for traversing the array (const version)  
    const T *end() const  
    {  
        return elements + size;  
    }  

    // Print elements in the array  
    void printElements() const  
    {  
        for (size_t i = 0; i < size; ++i)  
        {  
            std::cout << elements[i] << " ";  
        }  
        std::cout << std::endl;  
    }  

private:  
    // Extend array capacity  
    void reserve(size_t newCapacity)  
    {  
        if (newCapacity > capacity)  
        {  
            T *newElements = new T[newCapacity];  
            std::copy(elements, elements + size, newElements);  
            delete[] elements;  
            elements = newElements;  
            capacity = newCapacity;  
        }  
    }  
};  

int main()  
{  
    // Create a Vector object  
    Vector<int> myVector;  

    int N;  
    std::cin >> N;  
    // Read the newline  
    getchar();  

    std::string line;  
    for (int i = 0; i < N; i++)  
    {  
        // Read a full line  
        std::getline(std::cin, line);  
        std::istringstream iss(line);  
        std::string command;  
        iss >> command;  

        if (command == "push")  
        {  
            int value;  
            iss >> value;  
            myVector.push_back(value);  
        }  
        else if (command == "print")  
        {  
            if (myVector.getSize() == 0) {  
                std::cout << "empty" << std::endl;  
                continue;  
            }  
            myVector.printElements();  
        }  
        else if (command == "size")  
        {  
            std::cout << myVector.getSize() << std::endl;  
        }  
        else if (command == "get")  
        {  
            int index;  
            iss >> index;  
            std::cout << myVector[index] << std::endl;  
        }  
        else if (command == "insert")  
        {  
            int index, value;  
            iss >> index >> value;  
            myVector.insert(index, value);  
        }  
        else if (command == "pop")  
        {  
            myVector.pop_back();  
        }  
        else if (command == "iterator")  
        {  
            if (myVector.getSize() == 0)  
            {  
                std::cout << "empty" << std::endl;  
                continue;  
            }  
            for (auto it = myVector.begin(); it != myVector.end(); ++it)  
            {  
                std::cout << *it << " ";  
            }  
            std::cout << std::endl;  
        }  
        else if (command == "foreach")  
        {  
            if (myVector.getSize() == 0)  
            {  
                std::cout << "empty" << std::endl;  
                continue;  
            }  
            for (const auto &element : myVector)  
            {  
                std::cout << element << " ";  
            }  
            std::cout << std::endl;  
        }  
        else if (command == "clear")  
        {  
            myVector.clear();  
        }  
    }  
    return 0;  
}