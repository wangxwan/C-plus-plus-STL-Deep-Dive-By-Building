#pragma once

#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
class List
{
public:
    template <typename L>
    friend std::ostream &operator<<(std::ostream &os, const List<L> &pt);

private:
    // Defines the node structure
    struct Node
    {
        T data;     // Data
        Node *next; // Pointer to the next node
        Node *prev; // Pointer to the previous node

        // Constructor
        Node(const T &value, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };

    Node *head;  // Head node pointer
    Node *tail;  // Tail node pointer
    size_t size; // Number of nodes in the list

public:
    // Constructor
    List() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~List() { clear(); }

    // Adds an element to the end of the list
    void push_back(const T &value)
    {
        // Creates a new node
        Node *newNode = new Node(value, nullptr, tail);

        if (tail)
        {
            // If the list is not empty, set the next pointer of the tail node to the new node
            tail->next = newNode;
        }
        else
        {
            // If the list is empty, the new node is also the head node
            head = newNode;
        }

        // Updates the tail node pointer and list size
        tail = newNode;
        ++size;
    }

    // Adds an element to the beginning of the list
    void push_front(const T &value)
    {
        // Creates a new node
        Node *newNode = new Node(value, head, nullptr);

        if (head)
        {
            // If the list is not empty, set the prev pointer of the head node to the new node
            head->prev = newNode;
        }
        else
        {
            // If the list is empty, the new node is also the tail node
            tail = newNode;
        }

        // Updates the head node pointer and list size
        head = newNode;
        ++size;
    }

    // Gets the number of nodes in the list
    size_t getSize() const { return size; }

    // Accesses an element in the list
    T &operator[](size_t index)
    {
        // Traverses the list from the head node to find the node at the index
        Node *current = head;
        for (size_t i = 0; i < index; ++i)
        {
            if (!current)
            {
                // If the index is out of range, throw an exception
                throw std::out_of_range("Index out of range");
            }
            current = current->next;
        }

        // Returns the data in the node
        return current->data;
    }

    // const version of accessing an element in the list
    const T &operator[](size_t index) const
    {
        // Traverses the list from the head node to find the node at the index
        Node *current = head;
        for (size_t i = 0; i < index; ++i)
        {
            if (!current)
            {
                // If the index is out of range, throw an exception
                throw std::out_of_range("Index out of range");
            }
            current = current->next;
        }

        // Returns the data in the node
        return current->data;
    }

    // Removes the element at the end of the list
    void pop_back()
    {
        if (size > 0)
        {
            // Gets the node before the tail node
            Node *newTail = tail->prev;

            // Deletes the tail node
            delete tail;

            // Updates the tail pointer and list size
            tail = newTail;
            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr; // If the list is empty, set the head node to nullptr
            }

            --size;
        }
    }

    // Removes the element at the beginning of the list
    void pop_front()
    {
        if (size > 0)
        {
            // Gets the node after the head node
            Node *newHead = head->next;

            // Deletes the head node
            delete head;

            // Updates the head node pointer and list size
            head = newHead;
            if (head)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr; // If the list is empty, set the tail node to nullptr
            }

            --size;
        }
    }

    // Gets the node with the specified value
    Node *getNode(const T &val)
    {
        Node *node = head;
        while (node != nullptr && node->data != val)
        {
            node = node->next;
        }

        return node;
    }

    T *find(const T &val)
    {
        Node *node = getNode(val);
        if (node == nullptr)
        {
            return nullptr;
        }
        return &node->data;
    }

    // Removes the node with the specified value
    void remove(const T &val)
    {
        Node *node = head;
        while (node != nullptr && node->data != val)
        {
            node = node->next;
        }

        if (node == nullptr)
        {
            // Not found
            return;
        }
        if (node != head && node != tail)
        {
            // Neither the head nor the tail node
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else if (node == head && node == tail)
        {
            // Both the head and tail node
            head = nullptr;
            tail = nullptr;
        }
        else if (node == head)
        {
            // Is the head node
            head = node->next;
            if (head) head->prev = nullptr;
        }
        else
        {
            // Is the tail node
            tail = node->prev;
            tail->next = nullptr;
        }

        --size;

        delete node;
        node = nullptr;
    }

    bool empty() { return size == 0; }

    // Clears the list
    void clear()
    {
        while (head)
        {
            // Deletes nodes starting from the head node
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        // Updates the tail node pointer and list size
        tail = nullptr;
        size = 0;
    }

    // Returns an iterator to the beginning of the list
    Node *begin() { return head; }

    // Returns an iterator to the end of the list
    Node *end() { return nullptr; }

    // Returns a const iterator to the beginning of the list
    const Node *begin() const { return head; }

    // Returns a const iterator to the end of the list
    const Node *end() const { return nullptr; }

    // Prints the elements in the list
    void printElements() const
    {
        for (Node *current = head; current; current = current->next)
        {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }

};

// Overloads the << operator
template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &pt)
{
    for (typename List<T>::Node *current = pt.head; current;
         current = current->next)
    {
        os << " " << current->data;
    }
    os << std::endl;
    return os;
}

int main() {
    // Creates a List object
    List<int> myList;

    int N;
    std::cin >> N;
    // Reads the newline character
    getchar();
    std::string line;
    // Receives commands
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        if (command == "push_back") {
            iss >> value;
            myList.push_back(value);
        }

        if (command == "push_front") {
            iss >> value;
            myList.push_front(value);
        }

        if (command == "pop_back") {
            myList.pop_back();
        }

        if (command == "pop_front") {
            myList.pop_front();
        }

        if (command == "remove") {
            iss >> value;
            myList.remove(value);
        }

        if (command == "clear") {
            myList.clear();
        }

        if (command == "size") {
            std::cout << myList.getSize() << std::endl;
        }

        if (command == "get") {
            iss >> value;
            std::cout << myList[value] << std::endl;
        }

        if (command == "print") {
            if (myList.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myList.printElements();
            }
        }
    }
    return 0;

}
