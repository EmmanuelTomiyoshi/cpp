#include <iostream>
#include <stdexcept>
#include <fstream>

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        __attribute__((unused)) int result = a / b;

    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }
	   
	try {
        std::ifstream file("nonexistent.txt");
        if (!file.is_open()) {
            throw std::runtime_error("File not found");
        }
        // Perform file operations
    } catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}