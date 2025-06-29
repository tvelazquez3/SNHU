#include <iomanip>
#include <iostream>
#include "Investment.h"
using namespace std;

int main() {
	// don't add too much code here use it for other classes

	// default vals to be updated by user

	Investment app(0.0, 0.0, 0.0, 0); // initial, monthly, interest, years

	app.runInvestmentCalculations();

	// get bank member input logic added to investment.cpp

	return 0;
}