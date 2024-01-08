# Hands-on Implementation

The following example demonstrates how to implement a stack using C++ standard library containers (e.g., `std::deque`), providing basic stack operations. Note that the actual `std::stack` implementation is more complex and robust.

[MyStack Implementation](Implementation.cpp)

1. **`push` method:**

   ```cpp
   void push(const T& value) {
       data.push_back(value);
   }
   ```

   The `push` method adds a new element to the top of the stack. It uses the container's `push_back` method to append the element to the end of the underlying `data` container.

2. **`pop` method:**

   ```cpp
   void pop() {
       if (!empty()) {
           data.pop_back();
       } else {
           throw std::runtime_error("Stack is empty.");
       }
   }
   ```

   The `pop` method removes the top element from the stack.  It first checks if the stack is empty; if not, it removes the last element using `pop_back`. If the stack is empty, it throws a `runtime_error` exception.

3. **`top` method:**

   ```cpp
   T& top() {
       if (!empty()) {
           return data.back();
       } else {
           throw std::runtime_error("Stack is empty.");
       }
   }
   ```

   The `top` method returns a reference to the top element. If the stack is not empty, it returns a reference to the last element of the underlying container; otherwise, it throws a `runtime_error` exception.

4. **`empty` method:**

   ```cpp
   bool empty() const {
       return data.empty();
   }
   ```

   The `empty` method checks if the stack is empty. It returns a boolean value indicating whether the underlying `data` container is empty.

5. **`size` method:**

   ```cpp
   size_t size() const {
       return data.size();
   }
   ```

   The `size` method returns the number of elements in the stack. It achieves this by calling the `size` method of the underlying `data` container.  The `const` keyword indicates that this method does not modify the stack's state.  I've also added `else if` statements to the `main` function for better readability and to avoid unnecessary checks.  Finally, I added a `getchar()` call after reading `N` to consume the newline character left in the input buffer.