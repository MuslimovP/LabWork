#include "Date.h"
#include <iostream>

using namespace std;



DATE::DATE(int da, int mont, int yea)
{
	this->day = da;
	this->month = mont;
	this->year = yea;
}
DATE& DATE::operator++()
{
	++day;

	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		dayMonth[1] = 29;
	}

	if (day > dayMonth[month - 1]) 
	{
		++month;
		day = 1;
		
		if (month > 12) 
		{
			++year;
			month = 1;
		}
	}
	return *this;
}

// Перегрузка постфиксного оператора ++
DATE& DATE::operator++(int)
{
	DATE temp = *this;
	++(*this);
	return temp; 
}

DATE& DATE::operator--()
{
	--day;

	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		dayMonth[1] = 29;
	}
	if (day < 1)
	{
		--month;
		day = dayMonth[month - 1];
		if (month < 1) 
		{
			--year;
			month = 12;
			day = dayMonth[month - 1];
		}
	}
	return *this;
}

DATE& DATE::operator--(int)
{
	DATE temp = *this; 
	--(*this); 
	return temp; 
}

DATE DATE::operator+(int obj) const 
{
	DATE temp = *this; 
 
	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((temp.year % 4 == 0 && temp.year % 100 != 0) || (temp.year % 400 == 0)) 
	{
		dayMonth[1] = 29;
	}

	temp.day += obj;
	while (temp.day > dayMonth[temp.month - 1])
	{
		temp.day -= dayMonth[temp.month - 1];
		++temp.month;
		if (temp.month > 12)
		{
			temp.month = 1;
			++temp.year; 
		}
	}

	return temp;  
}

DATE DATE::operator-(int obj) const
{
	DATE temp = *this;

	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((temp.year % 4 == 0 && temp.year % 100 != 0) || (temp.year % 400 == 0))
	{
		dayMonth[1] = 29;
	}

	temp.day -= obj;
	while (temp.day < 0)
	{
		temp.day += dayMonth[temp.month - 1];
		--temp.month; 
		if (temp.month < 1)
		{
			temp.month = 12; 
			--temp.year; 
		}
	}

	return temp;
}

DATE& DATE::operator+=(int obj)
{
	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		dayMonth[1] = 29;
	}

	day += obj;
	while (day > dayMonth[month - 1])
	{
		day -= dayMonth[month - 1];
		++month;
		if (month > 12)
		{
			month = 1;
			++year;
		}
	}

	return *this;
}

DATE& DATE::operator-=(int obj)
{
	int dayMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		dayMonth[1] = 29;
	}

	day -= obj;
	while (day < 0)
	{
		day += dayMonth[month - 1];
		--month; 
		if (month < 1)
		{
			month = 12; 
			--year; 
		}
	}

	return *this;
}

// Перегрузка оператора <
bool DATE::operator<(const DATE& other) const
{
	if (year < other.year) 
	{
		return true;
	}
		
	if (year > other.year) 
	{
		return false;
	} 
	if (month < other.month) 
	{
		return true;
	}
	if (month > other.month) 
	{
		return false;
	}
	return day < other.day;
}

// Перегрузка оператора >
bool DATE::operator>(const DATE& other) const
{
	return other < *this;
}

// Перегрузка оператора <=
bool DATE::operator<=(const DATE& other) const
{
	return !(other < *this);
}

// Перегрузка оператора >=
bool DATE::operator>=(const DATE& other) const
{
	return !(*this < other);
}

// Перегрузка оператора ==
bool DATE::operator==(const DATE& other) const
{
	return day == other.day && month == other.month && year == other.year;
}

// Перегрузка оператора !=
bool DATE::operator!=(const DATE& other) const
{
	return !(*this == other);
}

// Метод для проверки корректности даты
bool DATE::DateValid(int da, int mont, int yea) const
{
	if (mont < 1 || mont > 12) return false;
	if (da < 1) return false;

	switch (mont)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return da <= 31;
	case 4: case 6: case 9: case 11:
		return da <= 30;
	case 2:
		if ((yea % 4 == 0 && yea % 100 != 0) || (yea % 400 == 0))
		{
			return da <= 29; // Високосный год
		}
		else
		{
			return da <= 28;
		}

	default:
		return false;
	}
}

void DATE::SetDay(int da)
{
	if (DateValid(da, month, year))  
	{
		this->day = da;
	}
	else 
	{
		cout << "Invalid day value." << endl;
		exit(EXIT_FAILURE); // Завершает выполнение программы с кодом ошибки
	}
}

void DATE::SetMonth(int mont)
{
	if (DateValid(day, mont, year)) 
	{
		this->month = mont;
	}
	else
	{
		cout << "Invalid month value." << endl;
		exit(EXIT_FAILURE); // Завершает выполнение программы с кодом ошибки
	}
}

void DATE::SetYear(int yea)
{
	if (DateValid(day, month, yea))  
	{
		this->year = yea;
	}
	else
	{
		cout << "Invalid year value." << endl;
		exit(EXIT_FAILURE); // Завершает выполнение программы с кодом ошибки
	}
}

// Установка даты с проверкой
void DATE::SetData(int da, int mont, int yea)
{
	if (DateValid(da, mont, yea))
	{
		this->day = da;
		this->month = mont;
		this->year = yea;
	}
	else 
	{
		cerr << "Invalid date" << endl;
		exit(EXIT_FAILURE); // Завершает выполнение программы с кодом ошибки
	}
}


int DATE::GetDay() const
{
	return day;   
}

int DATE::GetMonth() const
{
	return month;
}

int DATE::GetYear() const 
{
	return year;
}

void DATE::Print() const
{
	cout << day << "." << month << "." << year << endl; 
}

	
	