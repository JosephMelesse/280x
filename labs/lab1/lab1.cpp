/*
CIS 280X
Assignment 1
Melesse, Joseph
*/
#include <array>
#include <format> 
#include <gsl/gsl>
#include <iostream>
// prototype for the wages function that calculates and append on the salaries array
void wages(std::array<int, 11>& money);
// prototype for the display function that displays the final list of salary range
void display(const std::array<int, 11>& dollars);
// main loop for function
int main() {
  // salaries array 
  std::array<int, 11> salaries{};
  // calling both functions
  wages(salaries);
  display(salaries);
  return 0;
}
// the wages function that accepts the salary and computes and appends for each salary range
void wages(std::array<int, 11>& money) {
  double sales{};
  // constexpr constant values that get process on compile time and run the program faster
  constexpr double base = 200.0;
  constexpr double rate = 0.09;
  // prompt user to enter their sales
  std::cout << "Enter employee gross sales (-1 to end): ";
  std::cin >> sales;

  while (sales != -1) {
    double salary{base + rate * sales};
    std::cout << std::format("Employee Commission is ${:.2f}\n\n", salary);
    // ternary operator that appends each index according to the ternicated value that is calculated in x
    int x {gsl::narrow_cast<int>(salary) / 100};
    ++money[(x < 10) ? x : 10];
    // prompt user to enter their sales again
    std::cout << "Enter employee gross sales (-1 to end): ";
    std::cin >> sales; 
  }
}
// display each salary range using a range based for loop and format specifiers
void display(const std::array<int, 11>& dollars) {
  std::cout << "Employees in the range:";
  for (int i = 2; i <= 9; ++i) {
    std::cout << std::format("\n${}00-${}99 : {}", i, i, dollars[i]);
  }
  std::cout << std::format("\nOver $1000: {}\n", dollars[10]);
}
