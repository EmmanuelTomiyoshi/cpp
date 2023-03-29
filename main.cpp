#include <iostream>
#include <string>
#include <sstream>

int getIntegerInRange(int min, int max) {
    int value;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream stream(input);
		if (input.empty())
			continue ;
        if (!(stream >> value) || (value < min || value > max)) {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        }
        else {
            return value;
        }
    }
}

int main() {
    int userInput = getIntegerInRange(1, 8);
    std::cout << "User input: " << userInput << std::endl;
    return 0;
}