# Implementing vector

The Vector class includes a constructor, destructor, copy constructor, copy assignment operator, functions for adding elements, getting the number of elements, getting the capacity, and accessing elements.

First, here's [the complete basic implementation code](Implementation.cpp), followed by explanations:

1. **Constructor:** The constructor is simple, initializing everything to 0 or nullptr.

```c++
Vector() : elements(nullptr), capacity(0), size(0) {}
```

- Initializes the `Vector` object. `elements` is a pointer to a dynamically allocated array of type `T`, initially not allocated (`nullptr`).
- `capacity` represents the array's capacity, initially 0.
- `size` represents the current number of elements in the array, also initially 0.

2. **Destructor:**

```c++
~Vector() {
    delete[] elements;
}
```

- When a `Vector` object is destroyed, the destructor releases the dynamically allocated memory pointed to by `elements`.

3. **Copy Constructor:**

```c++
Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
    elements = new T[capacity];
    std::copy(other.elements, other.elements + size, elements);
}
```

- Used to create a new `Vector` object that is a copy of another `Vector` object.
- Allocates the same capacity as the original `Vector`.
- Copies the elements from the original `Vector` to the new object.

> `std::copy` is a standard library algorithm typically used to copy elements from one container to another. It takes three arguments: two iterators specifying the range of elements to be copied (begin and end iterators) and an iterator pointing to the beginning of the destination. Pointers are also a natural type of iterator.

4. **Copy Assignment Operator:**

```c++
Vector& operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        std::copy(other.elements, other.elements + size, elements);
    }
    return *this;
}
```

- Allows assigning the value of one `Vector` object to another.
- First, checks for self-assignment. If it's not self-assignment, it releases the current object's memory.
- Allocates new memory and copies all elements.
- Returns a reference to the current object.

5. **`push_back` Function:**

```c++
void push_back(const T& value) {
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : 2 * capacity);
    }
    elements[size++] = value;
}
```

- Adds a new element to the end of the `Vector`.
- If there's not enough capacity to store the new element, it expands the array's capacity using the `reserve` function.
- Adds the new element to the end of the array and increments `size`.

> Note that you can't simply double the `capacity`; you need to consider the boundary case of 0.

6. **`getSize` and `getCapacity` Functions:**

```c++
size_t getSize() const {
    return size;
}

size_t getCapacity() const {
    return capacity;
}
```

These are self-explanatory.

- `getSize` returns the number of elements in the `Vector`.
- `getCapacity` returns the capacity of the `Vector`.

7. **Subscript Operator:**

```c++
T& operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const T& operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
```

- Allows accessing elements in the `Vector` using the subscript operator.
- If the specified index is out of bounds (greater than or equal to `size`), it throws a `std::out_of_range` exception.
- Has both `const` and `non-const` versions.

> Note that it returns a reference, so modifications to the reference will be reflected in the `Vector`.

This code continues to provide more member functions for the custom `Vector` class. Here's an explanation of each function:

8. **`insert` Function:**

```c++
void insert(size_t index, const T& value) {
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    for (size_t i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    ++size;
}
```

- Inserts an element `value` at the specified position `index` in the `Vector`.
- If `index` is greater than `size`, it throws a `std::out_of_range` exception.
- If there's not enough capacity to store the new element, it expands the array's capacity using the `reserve` function.
- Shifts all elements after `index` one position to the right to make space for the new element.
- Places the new element at the `index` position.
- Increments the `Vector`'s `size`.

> Note that you can't simply double the `capacity`; you need to consider the boundary case of 0.

9. **`pop_back` Function:**

```c++
void pop_back() {
    if (size > 0) {
        --size;
    }
}
```

- Removes the last element of the `Vector`.
- Decrements the `Vector`'s `size`.
- Doesn't actually release memory, meaning even after calling `pop_back`, the `capacity` remains the same.

10. **`clear` Function:**

```c++
void clear() {
    size = 0;
}
```

- Clears all elements in the `Vector`.
- Sets `size` to 0.
- Similar to `pop_back`, `clear` doesn't release memory; `capacity` remains the same.

11. **Iterator-related functions `begin` and `end`:**

```c++
T* begin() {
    return elements;
}

T* end() {
    return elements + size;
}

const T* begin() const {
    return elements;
}

const T* end() const {
    return elements + size;
}
```

- The `begin` and `end` functions provide the ability to iterate over the `Vector`.
- The `non-const` versions return pointers to `elements` that can be used to modify elements in the `Vector`.
- The `const` versions return `const` pointers for read-only access.
- `begin` returns a pointer to the first element.
- `end` returns a pointer to one position past the last element, typically used to indicate the end of a range.

12. **`printElements` Function:**

```c++
void printElements() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}
```

- Prints all elements in the `Vector`.
- Iterates through the `Vector` and prints each element using `std::cout`.
- This function doesn't modify the `Vector`'s content, so it's declared as `const`.

