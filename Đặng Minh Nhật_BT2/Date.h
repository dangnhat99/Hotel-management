#include<iomanip>
#include <iostream>
using namespace std;
class Date
{
	private:
		int day;
		int month;
		int year; 
	public:
		Date();
		Date(int, int, int);
		Date(const Date&);
		~Date();
		void getDay(int);
		void getMonth(int);
		void getYear(int); 
		friend ostream& operator<<(ostream&, const Date&);
	    friend istream& operator>>(istream&, Date&);
		const Date& operator =(const Date&);
};
