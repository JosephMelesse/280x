/*
CIS 280X
Assignment 92
Melesse, Joseph
*/

#include <iostream>
#include <vector>

template<typename X>
bool palindrome(const std::vector<X> & vec);

int main(){
    // tests
    std::vector<int> a {1,2,3,2,1};
    std::vector<int> b {1,2,3,4};
    std::cout << (palindrome(a) ? "true\n" : "false\n");
    std::cout << (palindrome(b) ? "true\n" : "false\n");
}

template<typename Y>
bool palindrome(const std::vector<Y>& vec) {
   auto r{vec.crbegin()};
   auto i{vec.cbegin()};

   while (r != vec.crend() && i != vec.cend()) {
      if (*r != *i) { // values are not equal
         return false;
      }
      ++r;
      ++i;
   }

   return true; // the vector is a palindrome
}