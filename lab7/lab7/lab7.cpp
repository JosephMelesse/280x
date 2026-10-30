/*
CIS 280X
Assignment 7
Melesse, Joseph
*/
#include <iostream>
#include "Polynomial.h"

// main loop
int main() {
   // instantialize objects 
   Polynomial p1({{2, 3}, {-3, 2}, {4, 0}});
   Polynomial p2({{-1, 2}, {2, 1}, {3, 0}});
   Polynomial p3, p4, p5;

   std::cout << "Initial Polynomials:\n";
   std::cout << "p1: " << p1 << "\n";
   std::cout << "p2: " << p2 << "\n";

   // Demonstrate + operator
   p3 = p1 + p2;
   std::cout << "After addition (p1 + p2): " << p3 << "\n";

   // Demonstrate - operator
   p4 = p1 - p2;
   std::cout << "After subtraction (p1 - p2): " << p4 << "\n";

   // Demonstrate * operator
   p5 = p1 * p2;
   std::cout << "After multiplication (p1 * p2): " << p5 << "\n";

   // Demonstrate = operator
   Polynomial p6 = p1;
   std::cout << "After assignment (p6 = p1): " << p6 << "\n";

   // Demonstrate += operator
   p1 += p2;
   std::cout << "After addition assignment (p1 += p2): " << p1 << "\n";

   // Demonstrate -= operator
   p1 -= p2;
   std::cout << "After subtraction assignment (p1 -= p2): " << p1 << "\n";

   // Demonstrate *= operator
   p1 *= p2;
   std::cout << "After multiplication assignment (p1 *= p2): " << p1 << "\n";

}