#include <format>
#include <stdexcept>
#include "Hourly.h"

// constructor with validation
Hourly::Hourly(double wage, double hours)
  : m_wage{wage}, m_hours{hours}
{
    if (m_wage < 0.0) throw std::invalid_argument("Hourly wage must be >= 0.0");
    if (m_hours < 0.0) throw std::invalid_argument("Hours worked must be >= 0.0");
}

// calculate earnings with overtime
double Hourly::earnings() const {
    // regular pay
    if (m_hours <= 40.0) return m_wage * m_hours;
    // compute overtime pay
    return m_wage * 40.0 + m_wage * 1.5 * (m_hours - 40.0);
}

// format as text
std::string Hourly::toString() const {
    return std::format("hourly wage: ${:.2f}; hours worked: {:.2f}", m_wage, m_hours);
}