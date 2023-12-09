#include <iostream>
#include <deque>

int main() {
    // Create a deque with some elements
    std::deque<int> myDeque = {1, 2, 3, 4, 5};

    // Random access to elements in constant time
    std::cout << "Element at index 2: " << myDeque[2] << std::endl;
    std::cout << "Element at index 4: " << myDeque[4] << std::endl;

    return 0;
}