/*
CIS 280x
Assignment 11 - Part 2
Melesse, Joseph
*/
#include <iostream>
#include <regex>
#include <string>

// Counts how many times a regex pattern appears in the input string
int countMatches(const std::string& input, const std::regex& pattern) {
    return static_cast<int>(std::distance(
        std::sregex_iterator(input.begin(), input.end(), pattern),
        std::sregex_iterator()));
}

int main() {
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    const int digitCount = countMatches(text, std::regex("\\d"));
    const int nonDigitCount = countMatches(text, std::regex("\\D"));
    const int whitespaceCount = countMatches(text, std::regex("\\s"));
    const int wordCount = countMatches(text, std::regex("\\b\\w+\\b"));

    std::cout << "Number of digits: " << digitCount << '\n';
    std::cout << "Number of non-digit characters: " << nonDigitCount << '\n';
    std::cout << "Number of whitespace characters: " << whitespaceCount << '\n';
    std::cout << "Number of words: " << wordCount << '\n';

    return 0;
}
