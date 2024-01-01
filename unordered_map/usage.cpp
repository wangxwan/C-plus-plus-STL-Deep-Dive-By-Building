#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Create an unordered_map with std::string keys and int values
    std::unordered_map<std::string, int> wordCount;

    // Insert elements
    wordCount["apple"] = 1; // Method 1: Using subscript operator to insert or modify
    wordCount.insert({"banana", 2}); // Method 2: Using insert function to insert
    wordCount.emplace("cherry", 3); // Method 3: Using emplace for efficient in-place construction

    // Access elements
    std::cout << "apple count: " << wordCount["apple"] << std::endl; // Using subscript operator
    std::cout << "banana count: " << wordCount.at("banana") << std::endl; // Using at() method; throws std::out_of_range if key doesn't exist

    // Check if an element exists
    if (wordCount.find("cherry") != wordCount.end()) {
        std::cout << "cherry found" << std::endl;
    }

    // Update an element
    wordCount["apple"] = 5; // Update apple's count

    // Delete an element
    wordCount.erase("banana"); // Delete the element with key "banana"

    // Iterate through the unordered_map
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Get the size of the unordered_map
    std::cout << "Size of unordered_map: " << wordCount.size() << std::endl;

    return 0;
}