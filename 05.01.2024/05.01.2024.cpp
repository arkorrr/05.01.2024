#include <iostream>
#include <cassert>

using namespace std;

int Date[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int LeapDate[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int Month = 12;

class Drob   //Task1
{
	int numerator;
	int denominator;
public:
	Drob(int Numerator = 0, int Denominator = 1)
	{
		assert(denominator != 0);
		numerator = Numerator;
		denominator = Denominator;
	}
	/*void sum(Drob x)
	{
		if (denominator == x.denominator)
		{
			cout << "Sum of fractions =  " << numerator + x.numerator;
			cout << "/" << denominator << endl;
			return;
		}
		cout << "Sum of fractions =  " << numerator * x.denominator + x.numerator * denominator;
		cout << "/" << denominator * x.denominator << endl;
	}
	void subtraction(Drob x)
	{
		if (denominator == x.denominator)
		{
			cout << "Subtracting fractions =  " << numerator - x.numerator;
			cout << "/" << denominator << endl;
			return;
		}
		cout << "Subtracting fractions =  " << numerator * x.denominator - x.numerator * denominator;
		cout << "/" << denominator * x.denominator << endl;
	}
	void product(Drob x)
	{
		cout << "Product of fractions =  " << numerator * x.numerator;
		cout << "/" << denominator * x.denominator << endl;
	}
	void divide(Drob x)
	{
		cout << "Divide of fractions =  " << numerator * x.denominator;
		cout << "/" << denominator * x.numerator << endl;
	}*/
	Drob operator+(const Drob& x) const 
	{
		int num = numerator * x.denominator + x.numerator * denominator;
		int dem = denominator * x.denominator;
		return Drob(num, dem);
	}
		
	Drob operator-(const Drob& x) const 
	{
		int num = numerator * x.denominator - x.numerator * denominator;
		int dem = denominator * x.denominator;
		return Drob(num, dem);
	}
		
	Drob operator*(const Drob& x) const 
	{
		int num = numerator * x.numerator;
		int dem = denominator * x.denominator;
		return Drob(num, dem);
	}
		
	Drob operator/(const Drob& x) const 
	{
		if (x.numerator == 0) 
		{
		    cout << "ERROR: zero detected!";
			return 1;
		}
		int num = numerator * x.denominator;
		int dem = denominator * x.numerator;
		return Drob(num, dem);
	}
	void print() const 
	{
		cout << numerator << "/" << denominator << endl;
	}
};

class date		//Task2
{
	int day;
	int month;
	int year;
public:
	date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	bool isLeapYear(int year) 
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	int daysInMonth(int month, int year) 
	{
		if (month == 2) {
			return isLeapYear(year) ? 29 : 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 30;
		}
		else {
			return 31;
		}
	}
	date& operator+=(int days) 
	{
		day += days;

		while (day > 30) {
			month++;
			day -= 30;
			if (month > 12) {
				year++;
				month -= 12;
			}
		}

		return *this;
	}

	int operator-(const date& d) {
		int days = 0;

		for (int y = year; y < d.year; y++) {
			days += isLeapYear(y) ? 366 : 365;
		}

		for (int m = 1; m < month; m++) {
			days -= daysInMonth(m, year);
		}

		days -= day;

		for (int m = 1; m < d.month; m++) {
			days += daysInMonth(m, d.year);
		}

		days += d.day;

		return abs(days);
	}

	void print() 
	{
		cout << day << "." << month << "." << year << endl;
	}
};


int main()
{
	//Task1
	Drob f1(3, 2);
	Drob f2(2, 3);
	
	Drob Sum = f1 + f2;
	Sum.print();
	Drob Subtraction = f1 - f2;
	Subtraction.print();
	Drob Product = f1 * f2;
	Product.print();
	Drob Divide = f1 / f2;
	Divide.print();
	
	//Task2

	date date1(31,12,2023);
	date date2(1,1,2024);
	cout << "Date1 - Date2: " << date1 - date2 << endl;
	date1 += 250;
	date1.print();

}
	