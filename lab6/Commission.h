#pragma once
#include <string> 
#include "CompensationModel.h" 

// Commission model class
class Commission final : public CompensationModel {
public:
   // constructor 
   Commission(double grossSales, double commissionRate);
   // compute earnings
   double earnings() const override;
   // return text
   std::string toString() const override;
private:
   // sales amount
   double m_grossSales{0.0};
   // commission rate
   double m_commissionRate{0.0};
};

