#pragma once
#include <string>

class Fraction {
private:
    // initialize member variables
    int m_numerator;
    int m_denominator;
    void reduce();

public:
    // declare public methods
    Fraction(int numerator = 0, int denominator = 1);
    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
    std::string toString() const;
    double toDouble() const;
};