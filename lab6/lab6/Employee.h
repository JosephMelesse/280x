#pragma once 
#include <string> 
#include <string_view> 
#include "CompensationModel.h"

// Employee class declaration
class Employee final {
public:
   // Construct with name and model
   Employee(std::string_view name, CompensationModel* modelPtr);
   // Update compensation model pointer
   void setCompensationModel(CompensationModel* modelPtr);
   // Compute earnings via model
   double earnings() const;
   // String representation of employee
   std::string toString() const;
private:
   // Data members
   // Employee name storage
   std::string m_name{};
   // Compensation model pointer
   CompensationModel* m_modelPtr{}; 
};