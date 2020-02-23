#include "Date.h"

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
};
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& p)
{
	this->day = p.day;
	this->month = p.month;
	this->year = p.year;
}

Date::~Date()
{

};

void Date::getDay(int xday)
{
	this->day = day;
}

void Date::getMonth(int month)
{
	this->month = month;
}

void Date::getYear(int year)
{
	this->year = year;
}
const Date& Date::operator=(const Date& p)
{
	// TODO: insert return statement here
	this->day = p.day;
	this->month = p.month;
	this->year = p.year;
	return *this;
}
ostream& operator<<(ostream& o, const Date& p)
{
	if (p.day < 10) o << "0" << p.day;
	else o << p.day; 
	o << "/";
	if (p.month < 10) o << "0" << p.month;
	else o << p.month;
	o << "/";
	if (p.year < 10) o << "000" << p.year;
	else if (p.year < 100) o << "00" << p.year;
	else if (p.year < 1000) o << "0" << p.year;
	else o << p.year;
	//o << p.day << "/" << p.month << "/" << p.year;
	return o;
}

istream& operator>>(istream& i, Date& p)
{
YEAR:
	cout << "Nhap nam:";
	i >> p.year;
	if (p.year < 0)
	{
		cout << endl << "Nhap sai ngay, xin hay nhap lai!!" << endl;
		goto YEAR;
	}

MONTH:
	cout << "Nhap thang:";
	i >> p.month;
	if (p.month > 12 || p.month < 1)
	{
		cout << endl << "Nhap sai thang, xin hay nhap lai!!" << endl;
		goto MONTH;	
	}

DAY:
	cout << "Nhap ngay:";
	i >> p.day;
	if ( (p.month == 1) || (p.month == 3) || (p.month == 5) ||(p.month == 7) 
		|| (p.month == 8) || (p.month == 10) || (p.month == 12) )
		if (p.day < 0 || p.day>31)
		{
			cout << endl << "Nhap sai ngay, xin hay nhap lai!!" << endl;
			goto DAY;
			
		}
	if ( (p.month == 4) || (p.month == 6) || (p.month == 9) ||
		(p.month == 11) )
		if (p.day < 0 || p.day>30)
		{
			cout << endl << "Nhap sai ngay, xin hay nhap lai!!" << endl;
			goto DAY;
		}
	if (p.month == 2)
	{
		if (p.year % 4 == 0 && p.year % 100 != 0)
		{
			if (p.day < 0 || p.day>29)
			{
				cout << endl << "Nhap sai ngay, xin hay nhap lai!!" << endl;
				goto DAY;
			}
			else {};
		}
		else if (p.day < 0 || p.day>28)
		{
			cout << endl << "Nhap sai ngay, xin hay nhap lai!!" << endl;
			goto DAY;
		}
	}
	else {};
	
	return i;
}