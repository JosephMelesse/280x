/*
CIS 280X
Assignment 91
Melesse, Joseph
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <format>

int main() {
    std::vector<int> numbers;
    std::cout << "Enter non-negative integers (negative value to stop):\n";

    bool flag = true;
    while (flag) {
        int x;
        std::cin >> x;
        if (x < 0) {
            flag = false;
            break;
        }
        numbers.push_back(x);
    }

    std::size_t count = numbers.size();
    int sum = std::accumulate(numbers.begin(), numbers.end(), sum);

    // to prevent out of bound checks
    if (count == 0) {
        std::cout << "No non-negative numbers entered.\n"
                  << std::format("count: {}\nsum: {}\n", count, sum);
        return 0;
    }

    // store all the needed values
    auto [minIt, maxIt] = std::ranges::minmax_element(numbers);
    int min = *minIt;
    int max = *maxIt;
    int range = max - min;

    std::cout << std::format( "min: {}\nmax: {}\nrange: {}\ncount: {}\nsum: {}\n", min, max, range, count, sum);

    return 0;
}