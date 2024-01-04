#include <iostream>
#include <map> // For std::multimap

int main() {
    // Create a multimap with int keys and string values
    std::multimap<int, std::string> mm;

    // Insert elements; duplicate keys are allowed
    mm.insert(std::make_pair(1, "Apple"));
    mm.insert(std::make_pair(1, "Avocado"));
    mm.insert(std::make_pair(2, "Banana"));
    mm.insert(std::make_pair(3, "Cherry"));

    // Iterate through all elements
    std::cout << "Multimap elements:" << std::endl;
    for (const auto& element : mm) {
        std::cout << element.first << " => " << element.second << std::endl;
    }

    // Find all elements with key 1
    auto range = mm.equal_range(1); // Get a range encompassing all elements with key 1
    std::cout << "\nElements with key 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    // Erase all elements with key 2
    mm.erase(2);

    // Iterate through the multimap to see the result of the erase operation
    std::cout << "\nMultimap after erasing key 2:" << std::endl;
    for (const auto& element : mm) {
        std::cout << element.first << " => " << element.second << std::endl;
    }

    return 0;
}