
#include <string>
#include "Date.h"
class Phong
{
	private:
		string roomNum;  //thuoc tinh tim kiem binary search 
		int peopleNum;  //thuoc tinh update
		bool state;
		Date checkIn;
		Date checkOut;
		double price;  //thuoc tinh sap xep Bubble sort 
		static int count;
	public:
		Phong();
		Phong(string, int, bool, Date, Date, double);
		Phong(const Phong&);
		~Phong();
		void soPhong();
		string get_roomNum();
		int get_peopleNum(int);
		bool get_state(bool);
		Date get_checkIn(Date);
		Date get_checkOut(Date);
		void update_maphong();
		double get_price();
		friend ostream& operator << (ostream&, const Phong&);
		friend istream& operator >> (istream&, Phong&);
		friend int str(const string&); 
	    bool cmp(const string&);

	
};
