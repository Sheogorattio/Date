#pragma once
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
	static int daysInMonth[12];
	bool leap_y;
	unsigned long long daysInDate;
	
public:
	void SetDefFeb();
	void CheckLeap();
	void ResetDate(unsigned long long rez_DID);
	void ResetDID(unsigned long long a); // модификатор для числа дней в дате
	void Print() const;
	void SetDate(int y, int m, int d);
	int GetDIM(int index) const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDay(int a);
	void SetMonth(int a);
	void SetYear(int a);
	void SetDID();
	unsigned long long GetDID() const;
	Date();
	Date(int y, int m, int d);
	Date(const Date& obj);
	//Date& operator++(); //++obj
	//Date operator++(int); // obj++
	//Date& operator--(); //--obj
	//Date operator--(int); // obj--
	Date operator+(long long a)const;
	Date operator-(long long a)const;
	//Date operator-(const Date& obj)const;//date-date
	//Date& operator+=(long long a);
	//Date& operator-=(long long a);
	//bool operator>(const Date& obj)const;
	//bool operator<(const Date& obj)const;
	//bool operator>=(const Date& obj)const;
	//bool operator<=(const Date& obj)const;
	//bool operator==(const Date& obj)const;
	//bool operator!=(const Date& obj)const;
};



Date& operator++(Date& obj); //++obj
Date operator++(Date& obj, int); // obj++
Date& operator--(Date& obj); //--obj
Date operator--(Date& obj, int); // obj--
Date operator+(long long a, Date& obj);
Date operator-( Date& obj, long long a);
Date operator-(const Date& obj1, const Date& obj2);
Date& operator-=(Date& obj, long long a);
Date& operator+=(Date& obj, long long a);
bool operator>(const Date& obj1, const Date& obj2);
bool operator<(const Date& obj1, const Date& obj2);
bool operator>=(const Date& obj1, const Date& obj2);
bool operator<=(const Date& obj1, const Date& obj2);
bool operator==(const Date& obj1, const Date& obj2);
bool operator!=(const Date& obj1, const Date& obj2);