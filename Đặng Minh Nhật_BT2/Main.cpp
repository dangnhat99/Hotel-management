// Đặng Minh Nhật_BT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "List.h"

void menu()
{
	cout << endl << "------------QUAN LY PHONG KHACH SAN--------------";
	cout << endl << "1.Hien thi danh sach phong";
	cout << endl << "2.Chen them phong";
	cout << endl << "3.Cap nhap thong tin phong";
	cout << endl << "4.Xoa phong";
	cout << endl << "5.Tim kiem phong theo gia tien";
	cout << endl << "6.Sap xep phong theo gia tien";
	cout << endl << "0.Thoat chuong trinh";
	cout << endl << "-------------------------------------------------";
}

void selection(List& p)
{
	while (1)
	{
		menu();
		cout << endl << "Nhap vao 1 lua chon:";
		int chon;
		cin >> chon;
		switch (chon)
		{
		case 1:
			p.Display();
			break;
		case 2:
			p.Insert();
			p.Display();
			break;
		case 3:
			p.Update();
			p.Display();
			break;
		case 4:
			p.Delete();
			p.Display();
			break;
		case 5:
			p.TimKiem();
			break;
		case 6:
			p.Sort();
			p.Display();
			break;
		case 0:
			return;
		}
	}

}


int main()
{
	List p;
	
	//p.Display();
	//swap(*(p.data), *(p.data + 1));
	//p.Display();
	 selection(p);

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
