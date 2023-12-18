#include <iostream>
#include <set>

int main() {
    // Create a std::set object
    std::set<int> mySet;

    // Insert elements
    mySet.insert(42);
    mySet.insert(21);
    mySet.insert(63);
    mySet.insert(21); // Duplicate insertion is ignored

    // Erase an element
    mySet.erase(63);

    // Find an element
    auto it = mySet.find(42);
    if (it != mySet.end()) {
        // Element found
    }

    // Iterate and print the set
    for (const int& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}