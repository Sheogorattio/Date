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
	void SetDID();
	void CheckLeap();
public:
	void Print() const;
	void SetDate(int y, int m, int d);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	Date();
	Date(int y, int m, int d);
	Date(const Date& obj);
	Date& operator++(); //++obj
	Date operator++(int); // obj++
	Date& operator--(); //--obj
	Date operator--(int); // obj--
	Date operator+(long long a)const;
	Date operator-(long long a)const;
	Date operator-(const Date& obj)const;//date-date
	Date& operator+=(long long a);
	Date& operator-=(long long a);
	bool operator>(const Date& obj)const;
	bool operator<(const Date& obj)const;
	bool operator>=(const Date& obj)const;
	bool operator<=(const Date& obj)const;
	bool operator==(const Date& obj)const;
	bool operator!=(const Date& obj)const;
};


