#include <iostream>
#include <set>

int main() {
    // Create an empty multiset
    std::multiset<int> myMultiset;

    // Insert elements
    myMultiset.insert(42);
    myMultiset.insert(30);
    myMultiset.insert(56);
    myMultiset.insert(30); // Duplicates are allowed

    // Iterate and print
    std::cout << "Elements in the multiset: ";
    for (const auto& elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Erase elements
    myMultiset.erase(30); // Erases all elements with value 30

    // Iterate and print again
    std::cout << "Elements after erasing 30: ";
    for (const auto& elem : myMultiset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Find an element
    auto it = myMultiset.find(56);
    if (it != myMultiset.end()) {
        std::cout << "Element 56 found in the multiset." << std::endl;
    } else {
        std::cout << "Element 56 not found in the multiset." << std::endl;
    }

    // Get the number of elements
    std::size_t count = myMultiset.size();
    std::cout << "Number of elements in the multiset: " << count << std::endl;

    // Check if empty
    if (myMultiset.empty()) {
        std::cout << "The multiset is empty." << std::endl;
    } else {
        std::cout << "The multiset is not empty." << std::endl;
    }

    return 0;
}