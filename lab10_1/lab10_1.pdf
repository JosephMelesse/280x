/*
CIS 280X
Assignment 10.1
Melesse, Joseph
*/

// Word Frequency Counting.
#include <iostream>
#include <map>
#include <string>
#include <format>

int main() {
    std::map<std::string, int> wordCount;
    std::string sentence;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::string word;
    size_t index{0};
    size_t found;

    while ((found = sentence.find(' ', index)) != std::string::npos) {
        word = sentence.substr(index, found - index);

        if (!word.empty()){ 
            ++wordCount[word]; 
        }
        index = found + 1;
    }

    // Handle the last word
    word = sentence.substr(index);
    if (!word.empty()){ 
        ++wordCount[word]; 
    }
    // Display the word frequencies
    std::cout << std::format("{:<15} {}\n", "WORD", "COUNT");
    for (const auto& [w, count] : wordCount) {
        std::cout << std::format("{:<15} {}\n", w, count);
    }

    std::cout << std::format("Unique words: {}\n", wordCount.size());
}
