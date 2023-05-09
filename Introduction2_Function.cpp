#include "Introduction2_Function.h"

double calcMonthlyInterest(double interest, int monthInYear)
{
	//calculates monthly interest from annual interest and months in the year i.e., divides interest by 12
	return interest / monthInYear;
}

long calcMonthsOfLoan(int years, int monthsInYear)
{
	//calculates number of months of loan from years of loan i.e., multiplies maturity by 12
	return years * monthsInYear;
}