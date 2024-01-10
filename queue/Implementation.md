# Hands-on Implementation

[MyQueue Implementation](Implementation.cpp)

This `MyQueue` class is a generic queue implementation.  It uses template parameters `T` to specify the type of the queue elements and `Container` to specify the type of the underlying container, defaulting to `std::deque<T>`. This design provides flexibility, allowing users to choose different underlying containers as needed.

1. **Constructor:**  A constructor is not explicitly defined; `MyQueue` relies on the default constructor of `Container` (defaulting to `std::deque<T>`) to initialize the `data` member.
2. **`push` method:**
   - **Purpose:** Adds an element to the back of the queue.
   - **Parameter:** Takes a constant reference `const T& value` representing the element to be added.
   - **Implementation:** Calls the `push_back` member function of the `data` container to add the element to the back.
3. **`pop` method:**
   - **Purpose:** Removes the element at the front of the queue.
   - **Parameter:** None.
   - **Implementation:** First checks if the queue is empty. If not empty, it calls the `pop_front` member function of the `data` container to remove the first element. If the queue is empty, it throws a `std::runtime_error` exception.
4. **`front` method:**
   - **Purpose:** Accesses the element at the front of the queue.
   - **Parameter:** None.
   - **Implementation:** If the queue is not empty, it returns a reference to the first element of the `data` container. If the queue is empty, it throws a `std::runtime_error` exception.
5. **`back` method:**
   - **Purpose:** Accesses the element at the back of the queue.
   - **Parameter:** None.
   - **Implementation:** If the queue is not empty, it returns a reference to the last element of the `data` container. If the queue is empty, it throws a `std::runtime_error` exception.
6. **`empty` method:**
   - **Purpose:** Checks if the queue is empty.
   - **Parameter:** None.
   - **Implementation:** Returns a boolean value indicating whether the `data` container is empty, achieved by calling the `empty` member function of `data`.
7. **`size` method:**
   - **Purpose:** Returns the number of elements in the queue.
   - **Parameter:** None.
   - **Implementation:** Returns the number of elements in the `data` container, achieved by calling the `size` member function of `data`.  The `const` keyword indicates that this method does not modify the queue's state.