/*
CIS 280x
Assignment 4
Melesse, Joseph
*/

#include <iostream>
#include <format>

// SavingsAccount class definition
class SavingsAccount {
public:
    // constructor to initialize balance
    explicit SavingsAccount(double savingsBalance) : m_savingsBalance(savingsBalance) {}

    // adds one month of interest and returns the interest amount.
    double calculateMonthlyInterest() {
        double interest = (m_savingsBalance * m_annualInterestRate) / 12.0;
        m_savingsBalance += interest;
        return interest;
    }

    // modifies the static annual interest rate
    static void modifyInterestRate(double newInterestRate) {
        m_annualInterestRate = newInterestRate;
    }

    // returns the current balance
    double getBalance() const { return m_savingsBalance; }

private:
    // static variable to store the annual interest rate
    static double m_annualInterestRate;
    // instance variable to store the savings balance
    double m_savingsBalance;
};

// initialize static member
double SavingsAccount::m_annualInterestRate = 0.0;

int main() {
    // create two SavingsAccount objects
    SavingsAccount saver1{2000.00};
    SavingsAccount saver2{3000.00};

    // month 1 at 3%
    SavingsAccount::modifyInterestRate(0.03);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << std::format("After 1 month at 3%:\n  Saver1 balance: ${:.2f}\n  Saver2 balance: ${:.2f}\n\n", saver1.getBalance(), saver2.getBalance());

    // month 2 at 4%
    SavingsAccount::modifyInterestRate(0.04);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << std::format("After next month at 4%:\n  Saver1 balance: ${:.2f}\n  Saver2 balance: ${:.2f}\n", saver1.getBalance(), saver2.getBalance());
}
