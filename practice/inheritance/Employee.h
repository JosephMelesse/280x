// Fig. 10.20: Employee.h
// An Employee "has a" CompensationModel.
#pragma once // prevent multiple inclusions of header
#include <string>
#include <string_view>
#include "CompensationModel.h"
#include "Date.h"

class Employee final {
  public:
    Employee(std::string_view name, CompensationModel* modelPtr, const Date& birthDate);
    ~Employee();
    void setCompensationModel(CompensationModel *modelPtr);
    double earnings(int currentMonth) const; // pass current month for bonus logic
    std::string toString() const;
  private:
    std::string m_name{};
    Date m_birthDate; // <-- Correct type
    CompensationModel* m_modelPtr{}; 
};
