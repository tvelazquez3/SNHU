#include "Investment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Investment::Investment(double t_init, double t_deposit, double t_rate, int t_years) {
	m_InitialAmount = t_init;
	m_MonthlyDeposit = t_deposit;
	m_AnnualInterest = t_rate;
	m_years = t_years;
}

// setters

void Investment::setInitialAmount(double t_amt) { m_InitialAmount = t_amt; }
void Investment::setMonthlyDeposit(double t_amt) { m_MonthlyDeposit = t_amt; }
void Investment::setAnnualInterest(double t_rate) { m_AnnualInterest = t_rate; }
void Investment::setYears(int t_years) { m_years = t_years; }

void Investment::displayWithoutMonthlyDeposits() const { // calculate balances no extra deposits
	double total = m_InitialAmount;
	// header
	cout << "\n Balance and Interest Without Monthly Deposits\n";
	cout << "------------------------------------------------\n";
	cout << "Year\tYear End Balance\tYear End Earned Interest\n";

	for (int i = 1; i <= m_years; ++i) {
		double interest = total * (m_AnnualInterest / 100.0);
		total += interest;
		cout << fixed << setprecision(2);
		cout << i << "\t$" << total << "\t\t\t$" << interest << endl;

	}


}

void Investment::displayWithMonthlyDeposits() const { // calculate balances with extra deposits
	double total = m_InitialAmount;
	// header
	cout << "\n Balance and Interest With Monthly Deposits\n";
	cout << "---------------------------------------------\n";
	cout << "Year\tYear End Balance\tYear End Earned Interest\n";

	for (int i = 1; i <= m_years; ++i) {
		double yearlyInterest = 0.0;

		for (int j = 0; j < 12; ++j) {
			total += m_MonthlyDeposit;
			double interest = total * (m_AnnualInterest / 100.0 / 12.0); // monthly interest
			yearlyInterest += interest; // accumulated yearly interest
			total += interest; // add interest to total
		}

		cout << fixed << setprecision(2);
		cout << i << "\t$" << total << "\t\t\t$" << yearlyInterest << endl;
	}
}

void Investment::displayMonthlyBreakdown() {
	double total = m_InitialAmount;
	cout << "\n Monthly Breakdown of Investment\n";
	cout << "----------------------------------\n";
	cout << "Year\tMonth\tStart Balance\tDeposit\tInterest\nEnd Balance\n";

	for (int year = 1; year <= m_years; ++year) {
		for (int month = 1; month <= 12; ++month) {
			int monthNumber = (year - 1) * 12 + month; // finds month based on year

			double interest = (total + m_MonthlyDeposit) * (m_AnnualInterest / 100.0 / 12.0);
			double startBalance = total;
			total += m_MonthlyDeposit + interest; // adds deposit and interest

			cout << fixed << setprecision(2);
			cout << monthNumber << "\t$" << startBalance << "\t\t$"
				<< m_MonthlyDeposit << "\t$" << interest << "\t\t$" << total << endl;
		}
	}
} 

void Investment::runInvestmentCalculations() {
	char t_test = 0;
	// used for testing loop

	do {
		double t_InitialAmount;
		double t_MonthlyDeposit;
		double t_AnnualInterest;
		int t_years;

		cout << "Enter inital investment amount: $";
		cin >> t_InitialAmount;

		cout << "Enter monthly deposit amount: $";
		cin >> t_MonthlyDeposit;

		cout << "Enter desired annual interest rate (as a percentage): ";
		cin >> t_AnnualInterest;

		cout << "Enter number of years you wish to invest: ";
		cin >> t_years;

		m_InitialAmount = t_InitialAmount;
		m_MonthlyDeposit = t_MonthlyDeposit;
		m_AnnualInterest = t_AnnualInterest;
		m_years = t_years;

		displayWithoutMonthlyDeposits();
		displayWithMonthlyDeposits();

		char t_choice; // deciding if user wants monthly breakdown
		cout << "\nWould you like to see a monthly breakdown of your investment? (y/n): ";
		cin >> t_choice;

		if (t_choice == 'y' || t_choice == 'Y') {
			displayMonthlyBreakdown();
		}

		// return to menu

		cout << "Would you like to test new values? (y/n): ";
		char t_test;
		cin >> t_test;
			
	} while (t_test == 'y' || t_test == 'Y');

	cout << "Thank you for using Airgead Banking!\n";
}