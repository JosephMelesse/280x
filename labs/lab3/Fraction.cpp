#include "Fraction.h"
#include <numeric>
#include <format>
#include <iostream>

// define public methods
Fraction::Fraction(int numerator, int denominator):
   m_numerator{numerator}, m_denominator{denominator} {
   reduce();
}

void Fraction::reduce() {
   int gcd = std::gcd(m_numerator, m_denominator);
   // reduce numerator and denominator by their gcd
   m_numerator /= gcd;
   m_denominator /= gcd;
   // ensure denominator is positive
   if (m_denominator < 0) {
      m_numerator = -m_numerator;
      m_denominator = -m_denominator;
   }
}

// define arithmetic operations for addition
Fraction Fraction::add(const Fraction& other) const {
   Fraction result{
      m_numerator * other.m_denominator + other.m_numerator * m_denominator,
      m_denominator * other.m_denominator
   };
   return result;
}

// define arithmetic operations for subtraction
Fraction Fraction::subtract(const Fraction& other) const {
   Fraction result{
      m_numerator * other.m_denominator - other.m_numerator * m_denominator,
      m_denominator * other.m_denominator
   };
   return result;
}

// define arithmetic operations for multiplication
Fraction Fraction::multiply(const Fraction& other) const {
   Fraction result{
      m_numerator * other.m_numerator,
      m_denominator * other.m_denominator
   };
   return result;
}

// define arithmetic operations for division
Fraction Fraction::divide(const Fraction& other) const {
   if (other.m_numerator == 0) {
      std::cout << std::format("Error: Cannot divide by zero fraction. Returning 0/1.\n");
      return Fraction(0, 1);
   }
   Fraction result{
      m_numerator * other.m_denominator,
      m_denominator * other.m_numerator
   };
   return result;
}

// convert fraction to double
double Fraction::toDouble() const {
   return static_cast<double>(m_numerator) / m_denominator;
}

// convert fraction to string
std::string Fraction::toString() const {
   return std::format("{}/{}", m_numerator, m_denominator);
}