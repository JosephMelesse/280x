// includes
#include <format>
#include <stdexcept>
#include "Salaried.h" 

// ctor with validation
Salaried::Salaried(double salary) : m_salary{salary} {
   // validate salary
   if (m_salary < 0.0) {
      throw std::invalid_argument("Weekly salary must be >= 0.0");
   } 
} 

// compute earnings
double Salaried::earnings() const {return m_salary;}

// format text
std::string Salaried::toString() const {
   return std::format("salary: ${:.2f}", m_salary);
}

