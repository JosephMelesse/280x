// Fig. 9.23: Date.h
// Date class definition; member functions defined in Date.cpp
#pragma once // prevent multiple inclusions of header
#include <string>
class Date {
    public:
        static const int monthsPerYear{12}; // months in a year
        Date(int year, int month, int day);
        std::string toString() const; // date string in yyyy-mm-dd format
        ~Date(); // implementation displays when destruction occurs
        int getMonth() const { return m_month; }
    private:
        int m_year; // any year
        int m_month; // 1-12 (January-December)
        int m_day; // 1-31 based on month
        // utility function to check if day is proper for month and year
        bool checkDay(int day) const;
};