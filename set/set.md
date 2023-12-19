# std::set`

## Introduction

`std::set` is an ordered associative container provided by the C++ Standard Template Library (STL).  It's implemented using a Red-Black Tree, storing a unique set of elements sorted according to their values.

Here are some key features and operations:

- **Uniqueness:** `std::set` does not allow duplicate elements; each element is unique.  Attempts to insert duplicate elements are ignored.
- **Orderedness:** Elements in `std::set` are sorted in ascending order. This ordering is maintained by the self-balancing property of the Red-Black Tree, ensuring efficient insertion and deletion operations.
- **Element Insertion:** The `insert` member function adds elements to the set. If the element already exists, the insertion is ignored.

## How to Use

`std::set` is defined in the `<set>` header file.  Therefore, you need to include `<set>` before using `std::set` to access its definition and related operations.

[This code demonstrates basic `std::set` usage.](usage.cpp)

## Internal Mechanism

### Core Data Structure

`std::set` is an ordered associative container implemented using a Red-Black Tree. This provides efficient search, insertion, and deletion operations for unique elements.

Red-Black Trees have been previously introduced and won't be detailed here.  Essentially, `std::set` is an encapsulation of a Red-Black Tree.

### Node Structure

Each element in `std::set` maps to a node in the Red-Black Tree.  Because the Red-Black Tree maintains order and uniqueness, no extra processing of nodes is needed; only ensuring the node data type supports comparison operator overloading is required.

