#pragma once
#include <string> 
#include "CompensationModel.h" 

// Salaried compensation model
class Salaried final : public CompensationModel {
public:
   // construct with salary
   explicit Salaried(double salary);
   // compute earnings
   double earnings() const override;
   // text representation
   std::string toString() const override;
private:
   // weekly salary
   double m_salary{0.0};
};
