#include <iostream>
#include <map>

int main() {
    // Create a map with int keys and int values
    std::map<int, int> myMap;

    // Insert elements
    myMap.insert({1, 100});
    myMap[2] = 200; // Using the subscript operator to insert or modify
    myMap.insert({3, 300}); // Using an initializer list to insert

    // Access elements
    std::cout << "Element with key 2: " << myMap[2] << std::endl;

    // Iterate and print elements
    std::cout << "Iterating over elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    // Find an element
    auto search = myMap.find(2); // Find the element with key 2
    if (search != myMap.end()) {
        std::cout << "Found element with key 2: " << search->second << std::endl;
    } else {
        std::cout << "Element with key 2 not found." << std::endl;
    }

    // Delete an element
    myMap.erase(2); // Delete the element with key 2
    std::cout << "Element with key 2 erased." << std::endl;

    // Iterate and print elements after deletion
    std::cout << "Iterating over elements after deletion:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    return 0;
}