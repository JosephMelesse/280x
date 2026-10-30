// main.cpp
// Processing Employees with various CompensationModels.
#include <iostream>
#include <vector>
#include <memory>
#include <format>
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "Date.h"

int main() {
    int currentMonth;
    std::cout << "Enter the current payroll month as a number (1-12): ";
    std::cin >> currentMonth;

    // Create CompensationModels
    auto salariedModel = std::make_unique<Salaried>(800.0);
    auto commissionModel = std::make_unique<Commission>(10000, 0.06);

    // Create Employees with birth dates
    Date pierreBirth{1990, 10, 5};    // October birthday
    Date sierraBirth{1985, 7, 12};    // July birthday

    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<Employee>("Pierre Simon", salariedModel.get(), pierreBirth));
    employees.push_back(std::make_unique<Employee>("Sierra Dembo", commissionModel.get(), sierraBirth));

    // Print each Employee's information and earnings
    for (const auto& employee : employees) {
        // Print only the compensation model info (not birth date)
        std::string empStr = employee->toString();
        auto nameEnd = empStr.find('\n');
        std::cout << std::format("name: {}\n", empStr.substr(0, nameEnd));
        std::cout << empStr.substr(nameEnd + 1) << '\n';
        std::cout << std::format("earned ${:.2f}\n\n", employee->earnings(currentMonth));
    }
}
