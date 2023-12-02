#include <iostream>
#include <vector>

int main() {
    // Create an empty vector
    std::vector<int> myVector;

    // Create a vector using an initializer list
    std::vector<int> myVector2 = {1, 2, 3, 4, 5};

    // Insert an element at the end
    myVector.push_back(42);

    // Access elements using the subscript operator
    std::cout << "First element: " << myVector[0] << std::endl;

    // Print the size of the vector
    std::cout << "Size of myVector: " << myVector.size() << std::endl;

    return 0;
}