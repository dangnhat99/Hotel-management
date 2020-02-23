#include "Phong.h"
class List
{
private:
//public:
	Phong* data;
	int size; 
public:
	List();
	List(int);
	List(const List&);
	~List();
	void Display();
	void Insert();
	void Update();
	void Delete();
	friend void swap(Phong&, Phong&);
	void Sort(); 
	int Search(double&, const int&,const int & );
	void TimKiem();
}; 
