/*
CIS 280X
Assignment 51
Melesse, Joseph
*/

#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <memory>
#include <stdexcept>

// Date class
class Date {
public:
    static const int monthsPerYear{12}; 
    Date(int year, int month, int day);
    std::string toString() const;
    ~Date() = default;
    int getMonth() const { return m_month; }
private:
    int m_year{1900};
    int m_month{1};  
    int m_day{1};    
    bool checkDay(int day) const;
    static bool isLeap(int y) {
        return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
    }
};

// Date class implementation
Date::Date(int year, int month, int day) : m_year{year} {
    if (month < 1 || month > monthsPerYear) {
        throw std::invalid_argument("month must be 1-12");
    }
    m_month = month;
    if (!checkDay(day)) {
        throw std::invalid_argument("day out of range for current month and year");
    }
    m_day = day;
}

// checkDay function that checks if day is valid for month and year
bool Date::checkDay(int day) const {
    static const int daysPerMonth[monthsPerYear + 1] =
        {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (day <= 0) return false;
    if (m_month == 2 && isLeap(m_year)) {
        return day <= 29;
    }
    return day <= daysPerMonth[m_month];
}

// toString function that returns date in YYYY-MM-DD format
std::string Date::toString() const {
    return std::format("{:04}-{:02}-{:02}", m_year, m_month, m_day);
}

// Employee base class
class Employee {
public:
    Employee(std::string_view name, const Date& birthDate)
        : m_name{name}, m_birthDate{birthDate} {}
    virtual ~Employee() = default;

    virtual double earnings() const = 0;
    virtual std::string toString() const = 0;

    const std::string& name() const { return m_name; }
    int birthMonth() const { return m_birthDate.getMonth(); }
private:
    std::string m_name{};
    Date m_birthDate;
};

// SalariedEmployee class
class SalariedEmployee : public Employee {
public:
    SalariedEmployee(std::string_view name, const Date& birthDate, double weeklySalary)
        : Employee{name, birthDate}, m_weeklySalary{weeklySalary} {}
    double earnings() const override { return m_weeklySalary; }
    std::string toString() const override {
        return std::format("salary: ${:.2f}", m_weeklySalary);
    }
private:
    double m_weeklySalary{0.0};
};

// CommissionEmployee class
class CommissionEmployee : public Employee {
public:
    CommissionEmployee(std::string_view name, const Date& birthDate,
                       double grossSales, double commissionRate)
        : Employee{name, birthDate}, m_grossSales{grossSales}, m_commissionRate{commissionRate} {}
    double earnings() const override { return m_grossSales * m_commissionRate; }
    std::string toString() const override {
        return std::format("gross sales: ${:.2f}\ncommission rate: {:.2f}",
                           m_grossSales, m_commissionRate);
    }
private:
    double m_grossSales{0.0};
    double m_commissionRate{0.0};
};

// main function
int main() {
    int currentMonth;
    std::cout << "Enter the current payroll month as a number (1-12): ";
    std::cin >> currentMonth;

    std::vector<std::unique_ptr<Employee>> employees;
    employees.push_back(std::make_unique<SalariedEmployee>(
        "Pierre Simon", Date{1990, 10, 5}, 800.0));
    employees.push_back(std::make_unique<CommissionEmployee>(
        "Sierra Dembo", Date{1985, 7, 12}, 10000.0, 0.06));

    for (const auto& e : employees) {
        std::cout << std::format("name: {}\n", e->name());
        std::cout << e->toString() << '\n';
        double pay = e->earnings();
        if (e->birthMonth() == currentMonth) { pay += 100.0; }
        std::cout << std::format("earned ${:.2f}\n\n", pay);
    }
}
