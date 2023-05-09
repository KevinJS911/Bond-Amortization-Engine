#ifndef globals.h
const int gMonthsInYear = 12;

struct gMonthAmortization
{
	int year;
	int yearMonth;
	long loanMonth;
	double payment;
	double principal;
	double balance;
	double interest;

};
#endif // !globals.h

