#include <iostream>
#include <string>
#include "BankAccount.h"

int main()
{

    /* Initialize the variables that the user will give us. */
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;
    std::string userInput;
    bool running = true; // Used to check if the user would like to exit
    
    while (running == true) {

        /* Formatting our user input prompts */
        std::cout << "********************************" << std::endl;
        std::cout << "********** Data Input **********" << std::endl;
 
        /* Input validation for user input variables. */
        std::cout << "Initial Investment Amount: $";  
        while (!(std::cin >> initialInvestment) || initialInvestment < 0) {
            std::cout << "Initial Investment Amount: $";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        /* Input validation for user input variables. */
        std::cout << "Monthly Deposit: $";
        while (!(std::cin >> monthlyDeposit) || monthlyDeposit < 0) {
            std::cout << "Monthly Deposit: $";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        /* Input validation for user input variables. */
        std::cout << "Annual Interest: %";
        while (!(std::cin >> annualInterest) || annualInterest < 0) {
            std::cout << "Annual Interest: %";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        /* Input validation for user input variables. */
        std::cout << "Number of years: ";
        while (!(std::cin >> numberOfYears) || numberOfYears < 0) {
            std::cout << "Number of years: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }

        std::cout << std::endl;

        /* Using the values obtained from above, we initialize our BankAccount objects. */
        BankAccount monthlyAccount(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
        BankAccount nonMonthlyAccount(initialInvestment, annualInterest, numberOfYears);

        /* Call the specified functions to print out our reports. */
        std::cout << "   Balance and Interest With Additional Monthly Deposits" << std::endl;
        std::cout << "================================================================" << std::endl;
        std::cout << "Year\t\tYear End Balance\tYear End Earned Interest" << std::endl;
        std::cout << "================================================================" << std::endl;
        monthlyAccount.calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        std::cout << std::endl; // line break
        
        std::cout << "   Balance and Interest Without Additional Monthly Deposits" << std::endl;
        std::cout << "================================================================" << std::endl;
        std::cout << "Year\t\tYear End Balance\tYear End Earned Interest" << std::endl;
        std::cout << "================================================================" << std::endl;
        nonMonthlyAccount.calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterest, numberOfYears);

        /* Ask the user if they would like to try new values. */
        std::cout << "Would you like to continue? (Y/N)" << std::endl;
        std::cin >> userInput;

        if (userInput == "y" || userInput == "Y") { // check if the user types "y" or "Y", if not we exit the program.
            running = true;
        }
        else {
            running = false;
        }
    }

    return 0;
}