#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
private: // labeled m_ for private member variables
	double m_InitialAmount; // inital investment
	double m_MonthlyDeposit;
	double m_AnnualInterest;
	int m_years;

public:
	// constructor
	// labeled t_ for function parameters
	Investment(double t_init, double t_deposit, double t_rate, int t_years);

	void displayWithoutMonthlyDeposits() const;
	void displayWithMonthlyDeposits() const;
	void displayMonthlyBreakdown(); // option to have monthly breakdown
	void runInvestmentCalculations(); // monthly breakdown

	//setters
	void setInitialAmount(double t_amt);
	void setMonthlyDeposit(double t_amt);
	void setAnnualInterest(double t_rate);
	void setYears(int t_years);
};

#endif
