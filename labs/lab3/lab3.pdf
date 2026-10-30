#include <iostream>
#include "Fraction.h"

int main() {
    // make two objects of the Fraction class
    Fraction f1{1, 2};
    Fraction f2{3, 4};


    // call methods of those objects
    Fraction sum = f1.add(f2);
    Fraction diff = f1.subtract(f2);
    Fraction prod = f1.multiply(f2);
    Fraction quot = f1.divide(f2);

    // print results
    std::cout << "f1 = " << f1.toString() << "\n";
    std::cout << "f2 = " << f2.toString() << "\n";
    std::cout << "f1 + f2 = " << sum.toString() << "\n";
    std::cout << "f1 - f2 = " << diff.toString() << "\n";
    std::cout << "f1 * f2 = " << prod.toString() << "\n";
    std::cout << "f1 / f2 = " << quot.toString() << "\n";
    std::cout << "f1 as double = " << f1.toDouble() << "\n";
    std::cout << "f2 as double = " << f2.toDouble() << "\n";
}
