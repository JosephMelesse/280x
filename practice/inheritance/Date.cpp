// Fig. 9.24: Date.cpp
// Date class member-function definitions.
#include <array>
#include <format>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int year, int month, int day)
    : m_year{year}, m_month{month}, m_day{day} {
    if (m_month < 1 || m_month > monthsPerYear) { // validate the month
        throw std::invalid_argument{"month must be 1-12"};
    }
    if (!checkDay(day)) { // validate the day
        throw std::invalid_argument{
        "Invalid day for current month and year"};
    }
}

// gets string representation of a Date in the form yyyy-mm-dd
std::string Date::toString() const {
    return std::format("{:04}-{:02}-{:02}", m_year, m_month, m_day);
}

// output Date object to show when its destructor is called
Date::~Date() = default;

// utility function to confirm proper day value based on
// month and year; handles leap years, too
bool Date::checkDay(int day) const {
    // we ignore element 0
    static const std::array daysPerMonth{
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    // determine whether testDay is valid for specified month
    if (1 <= day && day <= daysPerMonth.at(m_month)) {
        return true;
    }
    // February 29 check for leap year
    if (m_month == 2 && day == 29 && (m_year % 400 == 0 ||
        (m_year % 4 == 0 && m_year % 100 != 0))) {
        return true;
    }
    return false; // invalid day, based on current m_month and m_year
}