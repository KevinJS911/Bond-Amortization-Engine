#include <iostream>
#include <cmath>
#include <iomanip>
#include "Introduction2_Function.h"
#include "global.h"

using namespace std;

enum PROGRAM_ARGUMENTS
{
	PRINCIPAL_VALUE = 1,
	INTEREST_RATE = 2,
	LOAN_YEARS = 3
};

enum PROGRAM_OUTPUT
{
	PO_YEAR = 10,
	PO_YEARMONTH = 10,
	PO_LOANMONTH = 12,
	PO_PAYMENT = 10,
	PO_PRINCIPAL = 10,
	PO_BALANCE =10,
	PO_INTEREST = 10
};

int main(int argc, char* argv[])
{
	cout << "argc: " << argc << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << "argv[" << i << "]: " << argv[i]<<endl;
	};

	double principal = 0.0;
	double interest = 0.0;
	int yearsOfLoan = 0;

	if (argc == 1)
	{
		cout << "Enter the principal: ";
		cin >> principal;

		cout << "Enter interest (in %): ";
		cin >> interest;
		interest /= 100;

		cout << "Enter the Years of Loan (in years): ";
		cin >> yearsOfLoan;
	}
	else {
		principal = atof(argv[PRINCIPAL_VALUE]);
		interest = atof(argv[INTEREST_RATE]);
		yearsOfLoan = atoi(argv[LOAN_YEARS]);
	};	

	cout << "Principal: " << principal << endl;
	cout << "Interest (in %): " << interest << endl;
	cout << "Principal (in years): " << yearsOfLoan << endl;

	double monthlyInterest = calcMonthlyInterest(interest, gMonthsInYear);
	long monthsOfLoan = calcMonthsOfLoan(yearsOfLoan, gMonthsInYear);

	double payment = 0.0;

	payment = principal * (monthlyInterest / (1 - pow((double)1 + monthlyInterest, (double)-monthsOfLoan)));
	cout << "Payment: " << setiosflags(ios::fixed)<< setprecision(2)<< payment << endl;

	double currPrincipal = 0.0;
	double currInterest = 0.0;
	double currBalance = 0.0;
	int year = 1;
	int yearMonth = 1;
	currBalance = principal;

	long currLoanMonth = 1;
	cout << setw(PO_YEAR) << "Year" << setw(PO_YEAR) << "YearMonth" << setw(PO_LOANMONTH) <<
		"LoanMonth" << setw(PO_PAYMENT) << "Payment" << setw(PO_PRINCIPAL) << 
		"Principal" << setw(PO_INTEREST) << "Interest"<<setw(PO_BALANCE) << 
		"Balance"  << endl;

	while (currLoanMonth <= monthsOfLoan)
	{
		currInterest = currBalance * monthlyInterest;
		currPrincipal = payment - currInterest;
		currBalance = currBalance - currPrincipal;
		gMonthAmortization amort;

		amort.year = year;
		amort.yearMonth = yearMonth;
		amort.loanMonth = currLoanMonth;
		amort.payment = payment;
		amort.principal = currPrincipal;
		amort.balance = currBalance;
		amort.interest = currInterest;

		cout << setw(PO_YEAR) << amort.year << setw(PO_YEAR) << amort.yearMonth<< 
			setw(PO_LOANMONTH) << amort.loanMonth << setw(PO_PAYMENT) << amort.payment << 
			setw(PO_PRINCIPAL) << amort.principal << setw(PO_INTEREST) << amort.interest <<
			setw(PO_BALANCE) << amort.balance << endl;

		currLoanMonth++;
		yearMonth++;
		if (yearMonth > 12) {
			yearMonth = 1;
			year++;
		};

	}
	cout << "Loan payments complete"<<endl;

	return 0;

}