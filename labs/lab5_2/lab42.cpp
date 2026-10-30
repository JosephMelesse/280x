/*
CIS 280X
Assignment 42
Melesse, Joseph
*/

#include <iostream>
#include <string>
#include <vector>
#include <format>

// Employee base class 
class Employee {
public:
    explicit Employee(std::string name) : m_name(std::move(name)) {}
    virtual ~Employee() = default;
    const std::string& name() const { return m_name; }
    // Polymorphic interface
    virtual double earnings() const = 0;
    virtual std::string detailsString() const = 0;

private:
    std::string m_name;
};

// SalariedEmployee class
class SalariedEmployee final : public Employee {
public:
    SalariedEmployee(std::string name, double weeklySalary)
        : Employee(std::move(name)), m_weeklySalary(weeklySalary) {}
    double earnings() const override { return m_weeklySalary; }
    std::string detailsString() const override {
        return std::format("salary: ${:.2f}", m_weeklySalary);
    }
private:
    double m_weeklySalary{0.0};
};

// CommissionEmployee class
class CommissionEmployee final : public Employee {
public:
    CommissionEmployee(std::string name, double grossSales, double commissionRate)
        : Employee(std::move(name)), m_grossSales(grossSales), m_commissionRate(commissionRate) {}

    double earnings() const override { return m_grossSales * m_commissionRate; }

    std::string detailsString() const override {
        return std::format("gross sales: ${:.2f}\ncommission rate: {:.2f}",
                           m_grossSales, m_commissionRate);
    }
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0}; 
};

// HourlyWorker class
class HourlyWorker final : public Employee {
public:
    HourlyWorker(std::string name, double wagePerHour, double hoursWorked)
        : Employee(std::move(name)), m_wage(wagePerHour), m_hours(hoursWorked) {}

    double earnings() const override {
        const double regularHours  = m_hours <= 40.0 ? m_hours : 40.0;
        const double overtimeHours = m_hours > 40.0 ? (m_hours - 40.0) : 0.0;
        return regularHours * m_wage + overtimeHours * m_wage * 1.5;
    }
    std::string detailsString() const override {
        // Order/labels match the sample output
        return std::format("hours: {:.2f}\nwage: ${:.2f}", m_hours, m_wage);
    }
private:
    double m_wage{0.0};   
    double m_hours{0.0};  
};

// Helpers to print exactly like the sample 
void printEmployeeByRef(const Employee& employee) {
    std::cout << std::format("name: {}\n", employee.name());
    std::cout << employee.detailsString() << "\n";
    std::cout << std::format("earned ${:.2f}\n\n", employee.earnings());
}

int main() {
    // Create the three employees from the sample
    SalariedEmployee pierre{"Pierre Simon", 800.00};
    CommissionEmployee sierra{"Sierra Dembo", 10000.00, 0.06};
    HourlyWorker susan{"Susan Green", 20.50, 45.00};  

    // Processed individually via variable names 
    std::cout << "EMPLOYEES PROCESSED INDIVIDUALLY VIA VARIABLE NAMES\n";
    std::cout << std::format("name: {}\n", pierre.name());
    std::cout << pierre.detailsString() << "\n";
    std::cout << std::format("earned ${:.2f}\n\n", pierre.earnings());

    std::cout << std::format("name: {}\n", sierra.name());
    std::cout << sierra.detailsString() << "\n";
    std::cout << std::format("earned ${:.2f}\n\n", sierra.earnings());

    std::cout << std::format("name: {}\n", susan.name());
    std::cout << susan.detailsString() << "\n";
    std::cout << std::format("earned ${:.2f}\n\n", susan.earnings());

    // Polymorphic processing via dynamic binding 
    std::cout << "EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";

    // Via base-class pointers
    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS POINTERS\n";
    std::vector<Employee*> staffPtrs{ &pierre, &sierra, &susan };
    for (const Employee* eptr : staffPtrs) {
        std::cout << std::format("name: {}\n", eptr->name());
        std::cout << eptr->detailsString() << "\n";
        std::cout << std::format("earned ${:.2f}\n\n", eptr->earnings());
    }

    // Via base-class references
    std::cout << "VIRTUAL FUNCTION CALLS MADE VIA BASE-CLASS REFERENCES\n";
    printEmployeeByRef(pierre);
    printEmployeeByRef(sierra);
    printEmployeeByRef(susan);
}
