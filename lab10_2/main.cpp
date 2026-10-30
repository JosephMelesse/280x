/*
CIS 280X
Assignment 10.2
Melesse, Joseph
*/

// Word Frequency Counting from a file (data.txt)
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <format>

int main() {
    std::ifstream inFile("data.txt");

    std::map<std::string, int> wordCount;
    std::string word;

    while (inFile >> word) {
        ++wordCount[word];
    }

    // Display the word frequencies
    std::cout << std::format("{:<15} {}\n", "WORD", "COUNT");

    for (const auto& [w, count] : wordCount) {
        std::cout << std::format("{:<15} {}\n", w, count);
    }

    std::cout << std::format("Unique words: {}\n", wordCount.size());

}