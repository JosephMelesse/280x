#pragma once
#include <iostream>
#include <vector>

// make a struct for a single polynomial term 
struct Term{
   int coefficient, exponent;
};

// define Polynomial class
class Polynomial{
   friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
public:
   // default constructor that creates the zero polynomial
   Polynomial() = default;

   // construct from a vector of terms
   Polynomial(const std::vector<Term>& terms): m_terms(terms){}

   // default destructor
   ~Polynomial() = default;

   // return a const reference to the internal term list
   const std::vector<Term>& getTerms() const noexcept { return m_terms; }

   /// Replace the internal term list with the provided vector
   void setTerms(const std::vector<Term>& terms) {m_terms = terms;}

   // prototype operator+ polynomial addition 
   Polynomial operator+(const Polynomial& rhs)const;
   // prototype operator- polynomial subtraction 
   Polynomial operator-(const Polynomial& rhs)const;
   // prototype operator* polynomial multiplication 
   Polynomial operator*(const Polynomial& rhs)const;

   // difine assignment and compound-assignment operators
   Polynomial operator=(const Polynomial& rhs);
   Polynomial operator+=(const Polynomial& rhs);
   Polynomial operator-=(const Polynomial& rhs);
   Polynomial operator*=(const Polynomial& rhs);
private:
   std::vector<Term> m_terms;
};
