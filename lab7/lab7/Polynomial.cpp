// Polynomial member-function definitions.
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include "Polynomial.h"

// define the + operator
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
   std::vector<Term> result{m_terms};

   for (const auto& term2 : rhs.m_terms) {
      bool found{false};

      for (auto& term1 : result) {
        if (term1.exponent == term2.exponent) {
        term1.coefficient += term2.coefficient;
        found = true;
        break;
        }
      }

      if (!found) {
        result.push_back(term2);
      }
   }

   return Polynomial{result};
}

// define the - operator
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
   std::vector<Term> result{m_terms};

   for (const auto& term2 : rhs.m_terms) {
      bool found{false};

      for (auto& term1 : result) {
        if (term1.exponent == term2.exponent) {
        term1.coefficient -= term2.coefficient;
        found = true;
        break;
        }
      }

      if (!found) {
        result.push_back({-term2.coefficient, term2.exponent});
      }
   }

   return Polynomial{result};
}

// define the * operator
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
   std::vector<Term> result;

   for (const auto& term1 : m_terms) {
      for (const auto& term2 : rhs.m_terms) {
        int newCoefficient = term1.coefficient * term2.coefficient;
        int newExponent = term1.exponent + term2.exponent;

        bool found{false};
        for (auto& resTerm : result) {
            if (resTerm.exponent == newExponent) {
                resTerm.coefficient += newCoefficient;
                found = true;
                break;
            }
        }

        if (!found) {
            result.push_back({newCoefficient, newExponent});
        }
      }
   }

   return Polynomial{result};
}

// define the = operator
Polynomial Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        m_terms = rhs.m_terms;
    }
    return *this;
}

// define the += operator
Polynomial Polynomial::operator+=(const Polynomial& rhs) {
   *this = *this + rhs;
   return *this; 
}

// define the -= operator
Polynomial Polynomial::operator-=(const Polynomial& rhs) {
   *this = *this - rhs;
   return *this;
}

// define the *= operator
Polynomial Polynomial::operator*=(const Polynomial& rhs) {
   *this = *this * rhs;
   return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
   bool firstTerm{true};
   bool hasConstantTerm{false};
   int constantCoefficient{0};

   // First, print all terms except the constant term
   for (const auto& term : poly.m_terms) {
        if (term.exponent == 0) {
            hasConstantTerm = true;
            constantCoefficient = term.coefficient;
            continue;
        }

        if (firstTerm) {
            if (term.coefficient < 0) {
            os << "-";
            }
            firstTerm = false;
        }
        else {
            if (term.coefficient > 0) {
            os << "+ ";
            }
            else {
            os << "- ";
            }
        }

        os << abs(term.coefficient) << "x^" << term.exponent << " ";
   }

   // Then, print the constant term if it exists
   if (hasConstantTerm) {
      if (firstTerm) {
         os << constantCoefficient;
      }
      else {
         if (constantCoefficient > 0) {
            os << "+ " << constantCoefficient;
         }
         else {
            os << "- " << abs(constantCoefficient);
         }
      }
   }

   return os;
}
