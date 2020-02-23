
#include"List.h"

List::List()
{
	this->size = 2;
	this->data = new Phong[this->size];
	*(this->data + 1) = Phong("1001", 3,true, Date(), Date(), 300);
}
List::List(int x)
{
	this->size = x;
	this->data = new Phong[this->size];
}
List::List(const List& p)
{
	this->size = p.size;
	this->data = new Phong[this->size];
	for (int i = 0; i < this->size; i++)
		*(this->data + i) = *(p.data + i);
}
List::~List()
{
	delete[] this->data;
}

void List::Display()
{
	cout << endl << "-------------------------DISPLAY-------------------" << endl;
	cout << "Ma phong    So nguoi o   Tinh trang   CheckIn     CheckOut    Gia phong  STT"<<endl;
	for (int i = 0; i < this->size; i++)
	{
		cout << *(this->data + i)<<"       "<<i+1<<endl;
	}
	cout << "-------------------------------------------------------"<<endl;
}

void List::Insert()
{
	cout << endl << "--------------INSERT--------------" << endl;

	this->size++; //tang size
	Phong* temp = new Phong[this->size]; //tao mang temp
	for (int i = 0; i < this->size - 1; i++)
		*(temp + i) = *(this->data + i);//gan temp=data
	
	int k;
	int select;
	do
	{
		cout << endl << "1.Chen dau mang" << endl;
		cout << "2.Chen cuoi mang" << endl;
		cout << "3.Chen vi tri k bat ki" << endl;
		cout << "--------------------------------" << endl;
		cout << "Nhap vao cong viec muon thuc hien:";
		cin >> select;
	} 
	while (select<0 || select>3);
	switch (select)
	{
	case 1: 
		k = 0;
		goto CASE1;
	case 2:
		k = this->size-1;
		goto CASE2 ;
	case 3:
		goto CASE3;
	}
CASE3:
	cout << "nhap vi tri k can chen:";
	cin >> k;
	k--;
	if (k<0 || k>this->size-1)
	{
		cout << "Vi tri k khong ton tai, nhap lai!!!"<<endl;
		goto CASE3;
	}
CASE1:
	for (int i = this->size-1; i >= k+1; i--)
		*(temp + i) = *(temp + i-1); //day cac vi tri tu k len 1 don vi	
CASE2:
	cout << "Nhap cac gia tri de chen:" << endl;

	cin >> *(temp + k);
	KIEMTRA:
		for (int i = 0; i < this->size-1; i++)
		{
			if ((temp + k)->cmp((this->data + i)->get_roomNum()))
			{
				cout << endl << endl << "Ma phong bi trung lap,nhap lai!!!" << endl << endl;
				(temp + k)->update_maphong();
				goto KIEMTRA;
			}
		}

	
	delete[] this->data;
	this->data = new Phong[this->size];
	for (int i = 0; i < this->size; i++)
	{
		*(this->data + i) = *(temp + i);
	}
}

void List::Update()
{
	cout<<endl<< "--------UPDATE-------"<<endl;
	string a;
	cout << "Nhap ma phong can update:";
	cin >> a;
	bool kt = 0;
	for (int i=0;i<this->size;i++)
	{ 
		if ((this->data + i)->cmp(a))
		{
			kt = 1;
			cin >> *(this->data + i);

		KIEMTRA:

			for (int j = 0; j < this->size; j++)
			{
				if (j!=i && (this->data+i)->cmp((this->data + j)->get_roomNum()))
				{
					cout << endl << endl << "Ma phong bi trung lap,nhap lai!!!" << endl << endl;
					(this->data + i )->update_maphong();
					goto KIEMTRA;
				}
			}
			break;
		}
	}
	if (!kt) cout << "Khong tim thay ma phong!!"<<endl;
}

void List::Delete()
{
	cout << endl << "--------------DELETE--------------" << endl;

	//this->size++; //tang size
	Phong* temp = new Phong[this->size]; //tao mang temp
	for (int i = 0; i < this->size ; i++)
		*(temp + i) = *(this->data + i);//gan temp=data

	int k;
	int select;
	do
	{
		cout << endl << "1.Xoa dau mang" << endl;
		cout << "2.Xoa cuoi mang" << endl;
		cout << "3.Xoa vi tri k bat ki" << endl;
		cout << "--------------------------------" << endl;
		cout << "Nhap vao cong viec muon thuc hien:";
		cin >> select;
	} while (select < 0 || select>3);
	switch (select)
	{
	case 1:
		k = 0;
		goto CASE1;
	case 2:
		k = this->size - 1;
		goto CASE2;
	case 3:
		goto CASE3;
	}
CASE3:
	cout << "Nhap vi tri k can xoa:";
	cin >> k;
	k--;
	if (k<0 || k>this->size - 1)
	{
		cout << "Vi tri k khong ton tai, nhap lai!!!" << endl;
		goto CASE3;
	}
CASE1:
	for (int i = k; i<this->size-1; i++)
		*(temp + i) = *(temp + i +1); //day cac vi tri tu k len 1 don vi	
CASE2:
	//cout << "Nhap cac gia tri de chen:" << endl;;
	//cin >> *(temp + k);
	this->size--; //giam size 1
	delete[] this->data;
	this->data = new Phong[this->size];
	for (int i = 0; i < this->size; i++)
	{
		*(this->data + i) = *(temp + i);
	}
}


void swap(Phong& a, Phong& b)
{
	Phong temp = a;
	a = b;
	b = temp;
}

void List::Sort()
{
	cout << endl << "------------------SAP XEP------------------" << endl;
	for (int i = this->size - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if ((this->data + j)->get_price() > (this->data + j + 1)->get_price()) 
				swap(*(this->data + j), *(this->data + j + 1));
	cout << endl << "-------------------DONE----------------------" << endl;
}

int List::Search(double& x, const int& left,const int& right)
{
	if (right < left) return -1;
	int mid = (right + left) / 2;
	if ((this->data + mid)->get_price() == x) return mid; 
	if (x < (this->data + mid)->get_price()) return (Search(x, left, mid - 1));
	else return Search(x, mid + 1, right);
}

void List::TimKiem()
{
	cout<<endl<< "-------------TIM KIEM-----------------"<<endl;
	List temp = List(*this);
	cout << endl << "***Tim kiem tren mang da sap xep***" << endl;
	temp.Sort();
	temp.Display();
	cout << "Nhap gia phong muon tim kiem:";
	double gia;
	cin >> gia;
	int location = temp.Search(gia, 0, temp.size);
	if (location == -1) cout << "Khong tim thay phong!!" << endl;
	else cout << "Tim thay phong o vi tri " << location + 1 << ":" << endl;
	cout << "Ma phong    So nguoi o   Tinh trang   CheckIn     CheckOut    Gia phong  STT" << endl;
	cout << *(temp.data + location) << "       " << location + 1 << endl;
	cout<<endl<< "-------------------DONE-----------------" << endl;
}


