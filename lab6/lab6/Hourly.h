#pragma once
#include <string>
#include "CompensationModel.h"

// Hourly compensation model
class Hourly final : public CompensationModel {
public:
    // Construct with wage and hours
    Hourly(double wage, double hours);
    // Compute earnings
    double earnings() const override;
    // Text representation
    std::string toString() const override;
private:
    // Hourly wage
    double m_wage{0.0};
    // Hours worked
    double m_hours{0.0};
};