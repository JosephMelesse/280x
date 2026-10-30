#include <format> 
#include <string> 
#include "CompensationModel.h"
#include "Employee.h" 

// construct employee with model
Employee::Employee(std::string_view name, CompensationModel* modelPtr)
   : m_name{name}, m_modelPtr{modelPtr} {}

// set compensation model pointer
void Employee::setCompensationModel(CompensationModel* modelPtr) {
   m_modelPtr = modelPtr;
}

// calculate earnings via model
double Employee::earnings() const {
   return m_modelPtr->earnings();
}; 

// format employee and model text
std::string Employee::toString() const {                       
   return std::format("{}\n{}", m_name, m_modelPtr->toString());
}