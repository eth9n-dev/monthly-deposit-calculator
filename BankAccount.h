#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
	private:
		double m_initialDeposit;
		double m_monthlyDeposit;
		double m_interestRate;
		int m_numberOfYears;

	public:
		BankAccount(double initialDeposit, double monthlyDeposit, double interestRate, int numberOfYears);
		BankAccount(double initialDeposit, double interestRate, int numberOfYears);

		void calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);
		void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
		void printDetails(int year, double yearEndBalance, double interestEarned);
};

#endif

