/*
 CIS 280x
 Assignment 11 - Part 1
 Melesse, Joseph
 */
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

// function that returns the modified character 
char rot13_char(char ch) {
    if (!std::isalpha(static_cast<char>(ch))) return ch; 
    const char base = std::islower(static_cast<char>(ch)) ? 'a' : 'A';
    return static_cast<char>(base + (ch - base + 13) % 26);
}

// function that returns the new string
std::string rot13(std::string_view text) {
    std::string result;
    result.reserve(text.size());
    for (char ch : text) {
        result.push_back(rot13_char(ch));
    }
    return result;
}

int main() {
    std::cout << "Enter a string: ";
    std::string message;
    std::getline(std::cin, message);

    std::string encrypted = rot13(message);
    std::cout << "Encrypted: " << encrypted << '\n';
}
