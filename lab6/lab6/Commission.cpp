#pragma once 
#include <string> 
#include <string_view> 
#include <format>
#include <stdexcept>
#include "CompensationModel.h"
#include "Commission.h"

// Simple employee wrapper
class Employee final {
public:
   // constructor
   Employee(std::string_view name, CompensationModel* modelPtr);
   // set compensation model method
   void setCompensationModel(CompensationModel* modelPtr);
   // earnings method
   double earnings() const;
   // to string method
   std::string toString() const;
private:
   // employee name
   std::string m_name{};
   // pointer to model
   CompensationModel* m_modelPtr{}; 
};

// ctor with validation
Commission::Commission(double grossSales, double commissionRate)
  : m_grossSales{grossSales}, m_commissionRate{commissionRate}
{
    // validate sales
    if (m_grossSales < 0.0)
        throw std::invalid_argument("Gross sales must be >= 0.0");
    // validate rate
    if (m_commissionRate <= 0.0 || m_commissionRate >= 1.0)
        throw std::invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

// compute earnings
double Commission::earnings() const {
    return m_grossSales * m_commissionRate;
}

// format data
std::string Commission::toString() const {
    return std::format("gross sales: ${:.2f}; commission rate: {:.2f}",
                       m_grossSales, m_commissionRate);
}