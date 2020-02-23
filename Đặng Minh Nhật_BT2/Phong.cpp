#include "Phong.h"

int Phong::count = 0;
Phong::Phong()
{
	this->roomNum = "1000";
	this->peopleNum = 1;
	this->state = 0;
	this->checkIn = Date(1, 1, 2000);
	this->checkOut = Date(2, 1, 2000);
	this->price = 200;
	Phong::count++;
}
Phong::Phong(string roomNum, int peopleNum, bool state, Date checkin, Date checkout, double price) :checkIn(checkin), checkOut(checkout)
{
	this->roomNum = roomNum;
	this->peopleNum = peopleNum;
	this->state = state;
	this->price = price;
	Phong::count++;
}

Phong::Phong(const Phong& p)
{
	this->roomNum = p.roomNum;
	this->state = p.state;
	this->peopleNum = p.peopleNum;
	this->checkIn = p.checkIn;
	this->checkOut = p.checkOut;
	this->price = p.price;
}

Phong::~Phong()
{
	Phong::count--;
}
void Phong::soPhong()
{
	cout << Phong::count;
}
string Phong::get_roomNum()
{	

	return this->roomNum ;
}
;

int str(const string& A)
{
	int i = 0;
	while (1)
	{
		if (A[i] != '\0') i++;
		else return i;
	}
}



void Phong::update_maphong()
{
	cout << endl << "Nhap lai ma phong moi:";
	cin.ignore();
	getline(cin, this->roomNum);
}

double Phong::get_price()
{
	return this->price;
}


bool Phong::cmp(const string& a)
{
	for (int i = 0; i < 4; i++)
		if (this->roomNum[i]!=a[i]) return false;
	return true;
}

ostream& operator<<(ostream& o, const Phong& p)
{
	o << setw(6) << p.roomNum;
	o << setw(11) << p.peopleNum;
	o<<setw(14)<< p.state;
	cout<<setw(8)<< p.checkIn<<setw(4)<< p.checkOut;
	o<<setw(7) << p.price;
	return o;
}

istream& operator>>(istream& i, Phong& p)
{
	// TODO: insert return statement here
	//nhap so phong
SoPhong: 
	cout<<endl<< "Ma phong abcd: + a la so tang, nhan gia tri 1->7" << endl
		      << "               + bcd la so phong, moi so nhan gia tri tu 0->9"<<endl<<endl;
	cout << ("Nhap ma phong theo mau (nhap lai neu sai):");
	cin.ignore();
	i >> p.roomNum;
	if (str(p.roomNum) != 4)
	{
		cout << endl << "Nhap qua 4 ki tu,nhap lai!!" << endl;
		goto SoPhong;
	}
	if (p.roomNum[0] < '1' || p.roomNum[0]>'7')
	{
		cout << endl << "Nhap sai tang,nhap lai!!"<<endl;
		goto SoPhong;
	}
	if (p.roomNum[1] < '0' || p.roomNum[1]>'9')
	{
		cout << endl << "Nhap sai so phong,nhap lai!!" << endl;
		goto SoPhong;
	}
	if (p.roomNum[2] < '0' || p.roomNum[2]>'9')
	{
		cout << endl << "Nhap sai so phong,nhap lai!!" << endl;
		goto SoPhong;
	}
	if (p.roomNum[3] < '0' || p.roomNum[3]>'9')
	{
		cout << endl << "Nhap sai so phong,nhap lai!!" << endl;
		goto SoPhong;
	}

	//so nguoi luu tru
SoNguoi:
	cout << "Nhap so nguoi luu tru toi da (1->4):";
	i >> p.peopleNum;
	if (p.peopleNum > 4 || p.peopleNum < 1) goto SoNguoi; 

	//tinh trang phong  
	cout << "Nhap tinh trang phong(trong=0, dang su dung=1):";
	i >> p.state; 
	//if (p.state > 1 || p.state < 0) goto TinhTrang; 
	
	if (!p.state)
	{
		// p.checkIn=checkIn.Date();
		 //p.checkOut = checkOut.Date();
		//date
		cout << "nhap thoi gian check in:" << endl;
		cin >> p.checkIn;
		cout << "nhap thoi gian check out:" << endl;
		cin >> p.checkOut;
	}
	else
	{
		p.checkIn = Date();
		p.checkOut = Date();
	}
GIAPHONG: 
	cout << "Nhap gia phong:";
		i >> p.price;
		if (p.price < 0) goto GIAPHONG;
	return i;
}
