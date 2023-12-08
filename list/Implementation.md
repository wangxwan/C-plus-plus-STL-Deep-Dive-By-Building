# Implementing `list`

This example demonstrates the basic functionality of the `List` class, including adding elements to the end and beginning of the list, accessing elements, deleting elements from the end and beginning, and clearing the list.

First, here's [the complete basic implementation code](Implementation.cpp)

Of course, below is a detailed explanation of each function, along with some potential pitfalls:

1. **Constructor**

```c++
List() : head(nullptr), tail(nullptr), size(0) {}
```

Initializes an empty linked list; the head and tail pointers are set to `nullptr`, and the list size is 0.

> **Pitfall:** Uninitialized member variables in C++ can lead to undefined behavior. This is different from Go or Rust.  Go and Rust (implementing the `Default` trait) initialize uninitialized integer members to 0 and boolean members to `false`, but C++ and C do not.  Programmers accustomed to Go should be aware of this.


2. **Destructor and `clear` function**

```c++
~List() {
    clear();
}
void clear() {
    while (head) {
        // Delete nodes starting from the head node
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Update the tail node pointer and list size
    tail = nullptr;
    size = 0;
}
```

The destructor calls the `clear()` method when destroying the linked list object, deleting all nodes and releasing memory. The `clear()` method simply clears the memory starting from the head node; the `next` pointer needs to be recorded before clearing.

> **Improvement:** Consider using smart pointers to avoid explicit memory reclamation.


3. **`push_back`**

```c++
void push_back(const T& value) {
    // Create a new node
    Node* newNode = new Node(value, nullptr, tail);

    if (tail) {
        // If the list is not empty, point the next pointer of the tail node to the new node
        tail->next = newNode;
    } else {
        // If the list is empty, the new node is also the head node
        head = newNode;
    }

    // Update the tail node pointer and list size
    tail = newNode;
    ++size;
}
```

Adds a new element to the end of the linked list. When a new node is created, the `prev` pointer is set to the original `tail`. It's necessary to check if the list is empty; if it is, `head` must also point to the new node because it's the first and last node.

Finally, `tail` points to the new node.

> **Pitfall:**  Needs to consider whether the list is empty.


3. **`push_front`**

```c++
void push_front(const T& value) {
    // Create a new node
    Node* newNode = new Node(value, head, nullptr);

    if (head) {
        // If the list is not empty, point the prev pointer of the head node to the new node
        head->prev = newNode;
    } else {
        // If the list is empty, the new node is also the tail node
        tail = newNode;
    }

    // Update the head node pointer and list size
    head = newNode;
    ++size;
}
```

Adds a new element to the head of the linked list. This is essentially the reverse logic of `push_back`; just swap the positions of `tail` and `head`.


4. **`getSize`**

```c++
size_t getSize() const {
    return size;
}
```

This function is simple; it returns the number of elements in the linked list.


5. **`operator[]`**

```c++
T& operator[](size_t index) {
    // Traverse the linked list from the head node to find the node at the index
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        if (!current) {
            // If index exceeds the list length, throw an exception
            throw std::out_of_range("Index out of range");
        }
        current = current->next;
    }

    // Return the data in the node
    return current->data;
}
```

This is the overload of the `[]` operator. It accesses elements in the linked list by index, returning a reference to the data of the corresponding node. The logic is to traverse the linked list from the head, which is simple, but it needs to handle out-of-bounds situations.

> **Pitfalls:**

* Handling out-of-bounds situations. The handling here is to throw an exception.
* Note that a reference is returned; otherwise, the elements cannot be updated through `[]`.


6. **`pop_back`**

```c++
void pop_back() {
    if (size > 0) {
        // Get the node before the tail node
        Node* newTail = tail->prev;

        // Delete the tail node
        delete tail;

        // Update the tail pointer and list size
        tail = newTail;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // If the list becomes empty, the head pointer should also be set to nullptr
        }

        --size;
    }
}
```

This function removes the last element from the linked list. Before deletion, it obtains the node preceding the tail node and sets it as the new `tail`.  However, it also checks if the list becomes empty after deletion; if so, the head pointer must also be set to `nullptr` to prevent `head` from becoming a **dangling pointer**.

> **Supplementary Knowledge: Dangling Pointer** A dangling pointer (or dangling reference) in C++ is a pointer that points to memory that has been freed or is no longer valid.  The presence of a dangling pointer can lead to undefined behavior, such as program crashes, data corruption, or difficult-to-debug errors.

> **Improvement:** Consider using smart pointers like `std::shared_ptr` to avoid explicit memory deallocation.


7. **`pop_front`**

```c++
void pop_front() {
    if (size > 0) {
        // Get the node after the head node
        Node* newHead = head->next;

        // Delete the head node
        delete head;

        // Update the head pointer and list size
        head = newHead;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // If the list becomes empty, the tail pointer should also be set to nullptr
        }

        --size;
    }
}
```

This function removes the first element from the linked list.  It's essentially the reverse logic of `pop_back`; simply swap the `tail` and `head` pointers in the `pop_back` implementation.

> **Potential Errors:**
* Forgetting to update the `head` pointer after deleting a node.
* Forgetting to reset `size` to 0 if the list becomes empty.


8. **Iterator: `begin` and `end`**

```c++
Node* begin() {
    return head;
}

// Returns an iterator to the end of the list
Node* end() {
    return nullptr;
}

// Const version of begin() for const-correctness
const Node* begin() const {
    return head;
}

// Const version of end() for const-correctness
const Node* end() const {
    return nullptr;
}
```

In this implementation, the iterators are simply pointers, with both `const` and `non-const` versions.  `begin()` returns a pointer to the first element of the linked list. `end()` returns a past-the-end iterator, which is `nullptr`, indicating the end of the list.


9. **`printElements`**

```c++
void printElements() const {
    for (Node* current = head; current; current = current->next) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;
}
```

This function iterates through the linked list and prints the value of each element.  This function could also be implemented using iterators; the logic is straightforward.

