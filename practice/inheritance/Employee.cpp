// Fig. 10.21: Employee.cpp
// Class Employee member-function definitions.

#include <format>
#include <string>
#include "CompensationModel.h"
#include "Employee.h"
// constructor performs "constructor injection" to initialize
// the CompensationModel pointer to a CompensationModel implementation
Employee::Employee(std::string_view name, CompensationModel* modelPtr, const Date &birthDate)
  : m_name{name}, m_modelPtr{modelPtr}, m_birthDate{birthDate} {}
Employee::~Employee() = default;
// set function performs "property injection" to change the
// CompensationModel pointer to a new CompensationModel implementation
void Employee::setCompensationModel(CompensationModel* modelPtr) {
  m_modelPtr = modelPtr;
}
// use the CompensationModel to calculate the Employee's earnings
double Employee::earnings(int currentMonth) const {
  double base = m_modelPtr->earnings();
  // Add $100 bonus if birthday month matches current month
  if (m_birthDate.getMonth() == currentMonth) {
    base += 100.0;
  }
  return base;
};
// return string representation of Employee object
std::string Employee::toString() const {
  return std::format("{}\nBirth date: {}\n{}", m_name, m_birthDate.toString(), m_modelPtr->toString());
}

