#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "ru");  
	DATE date;
	DATE date1;

	date.SetData(2, 12, 2020); // ���������� ���     
	date.Print(); // ������ ���� ��������� 
	date.SetDay(30); 
	date.Print(); 
	cout << "�������� ���������� ++" << endl;
	++date; 
	date.Print(); 
	cout << "�������� ����������� ++" << endl;
	date++;
	date.Print();
	cout << "�������� ���������� --" << endl;
	--date;
	date.Print(); 
	cout << "�������� ���������� --" << endl;
	date--;
	date.Print();
	cout << "�������� +" << endl;
	date1 = date + 21;
	date1.Print();  
	cout << "�������� -" << endl;
	date1 = date - 18;
	date1.Print();  
	cout << "�������� +=" << endl;
	date1 += 143;
	date1.Print();  
	cout << "�������� -=" << endl;
	date1 -= 238; 
	date1.Print();   
	
	DATE date2;
	date2.SetData(9, 5, 2021);
	// ��������� ���������
	cout << "��������� ���������" << endl;
	date1.Print();
	date2.Print();
	cout << "date1 == date2: " << (date1 == date2) << endl;
	cout << "date1 != date2: " << (date1 != date2) << endl;
	cout << "date1 < date2: " << (date1 < date2) << endl;
	cout << "date1 <= date2: " << (date1 <= date2) << endl;
	cout << "date1 > date2: " << (date1 > date2) << endl;
	cout << "date1 >= date2: " << (date1 >= date2) << endl;

	return 0; 
}