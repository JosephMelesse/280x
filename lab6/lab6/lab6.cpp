/*
CIS 280X
Assignment 6
Melesse, Joseph
*/
#include <format>
#include <iostream>
#include <vector>
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "Hourly.h"

int main() {
   // salaried model
   Salaried salaried{800.0};
   // salaried employee
   Employee salariedEmployee{"John Smith", &salaried};

   // commission model
   Commission commission{10000, .06};
   // commission employee
   Employee commissionEmployee{"Sue Jones", &commission};

   // hourly model
   Hourly hourly{20.0, 45.0}; 
   // hourly employee
   Employee hourlyEmployee{"Tim Dillon", &hourly};

   // employee list
   std::vector<Employee> employees{salariedEmployee, commissionEmployee, hourlyEmployee};

   // print all employees
   for (const Employee& employee : employees) {
      std::cout << std::format("{}\nearned: ${:.2f}\n\n",
         employee.toString(), employee.earnings());
   }
}