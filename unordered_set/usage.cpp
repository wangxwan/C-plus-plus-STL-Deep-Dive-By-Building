#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered set
    std::unordered_set<int> mySet;

    // Insert elements
    mySet.insert(42);
    mySet.insert(21);
    mySet.insert(63);

    // Find an element
    int searchElement = 21;
    auto it = mySet.find(searchElement);
    if (it != mySet.end()) {
        std::cout << "Element " << searchElement << " found in the set." << std::endl;
    } else {
        std::cout << "Element " << searchElement << " not found in the set." << std::endl;
    }

    // Delete an element
    int deleteElement = 42;
    size_t numErased = mySet.erase(deleteElement);
    if (numErased > 0) {
        std::cout << "Element " << deleteElement << " deleted from the set." << std::endl;
    } else {
        std::cout << "Element " << deleteElement << " not found in the set. Nothing deleted." << std::endl;
    }

    // Print set size
    std::cout << "Set size: " << mySet.size() << std::endl;

    // Iterate and print set elements
    std::cout << "Set elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}