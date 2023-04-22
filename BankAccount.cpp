#include "BankAccount.h"
#include <iostream>
#include <iomanip> // used for setprecision

/* BankAccount constructor with a monthly deposit variable */
BankAccount::BankAccount(double initialDeposit, double monthlyDeposit, double interestRate, int numberOfYears) {
	m_initialDeposit = initialDeposit;
	m_monthlyDeposit = monthlyDeposit;
	m_interestRate = interestRate;
	m_numberOfYears = numberOfYears;
}

/* BankAccount constructor without a monthly deposit variable */
BankAccount::BankAccount(double initialDeposit, double interestRate, int numberOfYears) {
	m_initialDeposit = initialDeposit;
	m_interestRate = interestRate;
	m_numberOfYears = numberOfYears;
	m_monthlyDeposit = 0;
}

/* Calculate and printing yearly balance with a monthly deposit. */
void BankAccount::calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {

	/* Declaring variable to be used */
	double openingAmount = initialInvestment;	// The opening amount at the start of each month
	double interestAmount;	// Interest amount per month
	double closingAmount;	// The closing amount at the end of the month
	double totalInterestEarned = 0.0;	// Total interest earned by the end of the year

	for (int i = 0; i < numberOfYears; i++) {	// loop as many times as years entered
		for (int j = 0; j < 12; j++) {	// loop through the 12 months in a year to get the proper interest amount
			interestAmount = (openingAmount + monthlyDeposit) * ((interestRate / 100) / 12);	// using compound interest equation given
			closingAmount = openingAmount + monthlyDeposit + interestAmount;
			
			totalInterestEarned += interestAmount;
			openingAmount = closingAmount;	// the new opening amount at the start of the next month = the closing amount of the previous month
		}

		printDetails(i + 1, openingAmount, totalInterestEarned);	// send the years information to be formatted by printDetails method
		totalInterestEarned = 0.0;	// reset yearly interest earned
	}

}

/* Calculate and printing yearly balance without a monthly deposit. */
void BankAccount::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

	/* Declaring variable to be used */
	double openingAmount = initialInvestment;	// The opening amount at the start of each month
	double interestAmount;	// Interest amount per month
	double closingAmount;	// The closing amount at the end of the month
	double totalInterestEarned = 0.0;	// Total interest earned by the end of the year

	for (int i = 0; i < numberOfYears; i++) {	// loop as many times as years entered
		for (int j = 0; j < 12; j++) {	// loop through the 12 months in a year to get the proper interest amount
			interestAmount = (openingAmount) * ((interestRate / 100) / 12);	// using compound interest equation given without monthly deposit
			closingAmount = openingAmount  + interestAmount;
			
			totalInterestEarned += interestAmount;
			openingAmount = closingAmount;	// the new opening amount at the start of the next month = the closing amount of the previous month
		}

		printDetails(i + 1, openingAmount, totalInterestEarned);	// send the years information to be formatted by printDetails method
		totalInterestEarned = 0.0;	// reset yearly interest earned
	}
}

void BankAccount::printDetails(int year, double yearEndBalance, double interestEarned) {
	std::cout << std::fixed;	// used to format our decimal output
	std::cout << std::setprecision(2);	// only 2 digits allowed after the decimal place

	std::cout << year << "\t\t" << yearEndBalance << "\t\t\t" << interestEarned << std::endl;	// output info to console
}