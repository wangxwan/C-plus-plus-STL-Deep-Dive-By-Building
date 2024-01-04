# Implementation Details

Because `multimap` requires ordering, it's typically implemented using a red-black tree. However, a basic red-black tree implementation doesn't inherently support duplicate keys. Therefore, the `Value` template parameter in the red-black tree cannot be a simple data type; a `std::list` or `std::vector` is used to store multiple `Value`s for a single key.

[This code snippet shows a possible implementation using a previously implemented RedBlackTree (assumed to be available).](Implementation.cpp)

