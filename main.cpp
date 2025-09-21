#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for std::stringstream

int main() {
    std::cout << "Enter some numbers on a single line: ";

    // Step 1: Read the entire line into a string
    std::string line;
    std::getline(std::cin, line);

    // Step 2: Create a stringstream from the line
    std::stringstream ss(line);

    // Step 3: Create a vector to store the numbers
    std::vector<int> numbers;
    int temp_num;

    // Step 4: Extract numbers from the stringstream one by one
    while (ss >> temp_num) {
        numbers.push_back(temp_num);
    }

    // Now, you can use the vector of numbers
    std::cout << "\nYou entered " << numbers.size() << " numbers:" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}