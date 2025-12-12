#include <iostream>
#include <bitset>

int main()
{
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    // Create a bitset with a specified number of bits (e.g., 8 for a byte)
    std::bitset<16> binary(decimalNumber); // Adjust the size as needed

    std::cout << "Binary: " << binary << std::endl;
    return 0;
}