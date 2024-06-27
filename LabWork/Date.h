#pragma once
class DATE
{
	int day;
	int	month;
	int	year;
public:

	bool DateValid(int da, int mont, int yea) const;
	DATE() {};
	DATE(int da, int mont, int yea);

	void SetDay(int da);
	void SetMonth(int mont); 
	void SetYear(int yea); 
	void SetData(int da, int mont, int yea);

	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	DATE& operator++();
	DATE& operator++(int);
	DATE& operator--();
	DATE& operator--(int);
	DATE operator+(int obj)const;
	DATE operator-(int obj)const;
	DATE& operator+=(int obj); 
	DATE& operator-=(int obj);
	 
	bool operator<(const DATE& other) const; 
	bool operator>(const DATE& other) const;
	bool operator<=(const DATE& other) const;
	bool operator>=(const DATE& other) const;
	bool operator==(const DATE& other) const;
	bool operator!=(const DATE& other) const; 

	void Print()const;

};

