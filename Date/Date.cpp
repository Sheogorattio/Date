#include <iostream>
#include "Date.h"

int Date::daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//.						     1   2   3   4   5   6   7   8   9  10  11  12
void Date::SetDID() {// тут перевод всей даты в число дней (дни прошедших годов + дни прошедших мес€це + прошедшие дни) ”ƒќЅЌќ ƒЋя —–ј¬Ќ»¬јЌ»я ƒј“
	daysInDate = day;
	for (int i = 0; i < month; i++) {
		daysInDate += daysInMonth[i];
	}
	int num_leap_y = year / 4;// число добавочных дней с каждого високосного года
	daysInDate += 365 * year + num_leap_y;
}

void Date::ResetDID(unsigned long long a) {
	daysInDate = a;
}

void Date::CheckLeap() {//проверка високосности
	if (year % 4 == 0) {
		leap_y = true;
		daysInMonth[1] = 29;
	}
	else {
		leap_y = false;
		daysInMonth[1] = 28;
	}
}

void Date::Print()const {
	cout << "DATE: \t" << day << "." << month+1 << "." << year << "\t\t" << leap_y << "\t" << daysInDate << endl;
}

void Date::SetDate(int y, int m, int d)
{
	year = 0;
	if (y % 4 == 0) {
		leap_y = true;
		daysInMonth[1] = 29;
	}
	else {
		leap_y = false;
	}
	year = y;
	while (m > 12 || m <= 0) {
		cout << "enter correct month\n";
		cin >> m;
	}
	month = m-1;
	while (d > daysInMonth[month] || d <= 0) {
		cout << "enter correct day\n";
		cin >> d;
	}
	day = d;

	daysInMonth[1] = 28;

	SetDID();
}

int Date::GetDIM(int index) const {
	return daysInMonth[index];
}

int Date::GetDay ()const
{
	return day;
}

int Date::GetMonth()const
{
	return month;
}

int Date::GetYear()const
{
	return year;
}

Date::Date()
{
	day = 1;
	month = 0;
	year = 0;
	leap_y = true;
	daysInDate = 1;
}

Date::Date(int y, int m, int d)
{
	year = 0;
	if (y % 4 == 0) {
		leap_y = true;
		daysInMonth[1] = 29;
	}
	else {
		leap_y = false;
	}
	year = y;
	while (m > 12 || m < 0) {
		cout << "enter correct month\n";
		cin >> m;
	}
		month = m-1;
	while (d > daysInMonth[month] || d <= 0) {
		cout << "enter correct day\n";
		cin >> d;
	}
	day = d;

	daysInMonth[1] = 28;

	SetDID();
}

Date::Date(const Date& obj)
{
	day = obj.day;
	month = obj.month;
	year = obj.year;
	leap_y = obj.leap_y;
	daysInDate = obj.daysInDate;
}

//Date& Date::operator++() {
//	++day;
//	if (day > daysInMonth[month]) {
//		day = 1;
//		++month;
//	}
//	if (month > 11) {
//		month = 0;
//		++year;
//	}
//
//	SetDID();
//	return *this;
//}
//
//Date Date::operator++(int) {
//	Date temp = *this;
//
//	++day;
//	if (day > daysInMonth[month]) {
//		day = 1;
//		++month;
//	}
//	if (month > 11) {
//		month = 0;
//		++year;
//	}
//
//	SetDID();
//	return temp;
//}
//
//Date& Date::operator--() {
//	--day;
//	if (day < 1) {
//		if (month > 1) {
//			--month;
//			day = daysInMonth[month];
//		}
//		else {
//			month = 11;
//			day = daysInMonth[month];
//			--year;
//		}
//	}
//	SetDID();
//	return *this;
//}
//
//Date Date::operator--(int) {
//	Date temp = *this;
//
//	--day;
//	if (day < 1) {
//		if (month > 1) {
//			--month;
//			day = daysInMonth[month];
//		}
//		else {
//			month = 11;
//			day = daysInMonth[month];
//			--year;
//		}
//	}
//
//	SetDID();
//	return temp;
//}
//
Date Date::operator+(long long a)const {
	Date temp= *this;
	temp.day += a;
	temp.CheckLeap();
	while (temp.day > daysInMonth[temp.month]) { // реализовано добавление бесконечно большого числа(в пределах int)
		temp.day -= daysInMonth[temp.month];
		temp.month++;
		if (temp.month > 11) {
			temp.month = 0;
			temp.year++;
			temp.CheckLeap();
		}
	}
	daysInMonth[1] = 28;
	temp.SetDID();
	return temp;
}

Date Date::operator-(long long a)const { // реализовано вычитание бесконечно большого числа(в пределах long long)
	Date temp(*this);
	temp.day -= a;
	while (temp.day < 1) {
		if (temp.month > 0) {
			temp.month--;
		}
		else {
			temp.month = 11;
			temp.year--;
		}
		temp.CheckLeap();
		temp.day += daysInMonth[temp.month];
		}
	temp.SetDID();
	return temp;
}
void Date::SetDefFeb() {
	daysInMonth[1] = 28;
}

//Date Date::operator-(const Date& obj)const {
//	if (year < obj.year) {
//		cout << "error\n";
//		return *this;
//	}
//	long long diff = daysInDate - obj.daysInDate;
//	Date temp;
//	return temp+diff-1;//вычитаетс€ 1 из-за того, что при в конструкторе по умолчанию temp инициализируетс€ одним днЄм (первое €нвар€ нулевого года)
//}

//Date& Date::operator-=(long long a) {
//	day -= a;
//	while (day < 1) {
//		if (month > 0) {
//			month--;
//		}
//		else {
//			month = 11;
//			year--;
//		}
//		CheckLeap();
//		day += daysInMonth[month];
//	}
//	SetDID();
//	return *this;
//}
//
//Date& Date::operator+=(long long a) {
//	day += a;
//	CheckLeap();
//	while (day > daysInMonth[month]) {
//		day -= daysInMonth[month];
//		month++;
//		if (month > 11) {
//			month = 0;
//			year++;
//			CheckLeap();
//		}
//	}
//	daysInMonth[1] = 28;
//	SetDID();
//	return *this;
//}
//
//bool Date::operator>(const Date& obj)const {
//	return daysInDate > obj.daysInDate ? 1 : 0;
//}
//
//bool Date::operator<(const Date& obj)const {
//	return daysInDate < obj.daysInDate ? 1 : 0;
//}
//
//bool Date::operator>=(const Date& obj)const {
//	return daysInDate >= obj.daysInDate ? 1 : 0;
//}
//
//bool Date::operator<=(const Date& obj)const {
//	return daysInDate <= obj.daysInDate ? 1 : 0;
//}
//
//bool Date::operator==(const Date& obj)const {
//	return daysInDate == obj.daysInDate ? 1 : 0;
//}
//
//bool Date::operator!=(const Date& obj)const {
//	return daysInDate != obj.daysInDate ? 1 : 0;
//}

unsigned long long Date::GetDID() const {
	return daysInDate;
}

void Date::SetDay(int a) {
	day = a;
	SetDID();
	ResetDate(daysInDate);
}

void Date::SetMonth(int a) {
	while (a - 1 > 11 || a - 1 < 0) {
		cout << "error\nenter month again\n";
		cin >> a;
	}
	month = a-1;
	CheckLeap();
	if (day > daysInMonth[month]) {
		day -= daysInMonth[month];
		month++;
	}
	daysInMonth[1] = 28;
	SetDID();
}

void Date::SetYear(int a) {
	while (a < 0) {
		cout << "error\nenter year again\n";
		cin >> a;
	}
	year = a;
	CheckLeap();
	if (day > daysInMonth[month]) {
		day -= daysInMonth[month];
		month++;
	}
	daysInMonth[1] = 28;
	SetDID();
}

void Date::ResetDate( unsigned long long rez_DID) {//дл€ операции вида дата - дата и дата + дата		rez_DID - результат вычитани€ или сложени€ daysInDate каждого обЏекта
	daysInMonth[1] = 28;
	SetDID();
	unsigned long long _DID = rez_DID;
	int _year = (int)rez_DID / 365;
	year = _year;
	_DID -= _year * 365;
	int _leap = _year / 4;
	month = 0;
	CheckLeap();
	while (_DID > daysInMonth[month]) {
		_DID -= daysInMonth[month];
		++month;
	}
	day = _DID +_leap/2;
	if (day > daysInMonth[month]) {
		day -= daysInMonth[month];
		month++;
	}
	daysInMonth[1] = 28;
}

Date& operator++(Date& obj) {
	obj.SetDay(obj.GetDay() + 1);
	if (obj.GetDay() > obj.GetDIM(obj.GetMonth())) {
		obj.SetDay(1);
		obj.SetMonth(obj.GetMonth() + 1);
	}
	if (obj.GetMonth() > 11) {
		obj.SetMonth(0);
		obj.SetYear(obj.GetYear() + 1);
	}

	obj.SetDID();
	return obj;
}

Date operator++(Date& obj, int) {
	Date temp = obj;
	obj.SetDay(obj.GetDay()+1);
	if (obj.GetDay() > obj.GetDIM(obj.GetMonth())) {
		obj.SetDay(1);
		obj.SetMonth(obj.GetMonth()+1);
	}
	if (obj.GetMonth() > 11) {
		obj.SetMonth(0);
		obj.SetYear(obj.GetYear()+1);
	}
	obj.SetDID();
	return temp;
}

Date& operator--(Date& obj) {
	obj.SetDay(obj.GetDay()-1);
	if (obj.GetDay() < 1) {
		if (obj.GetMonth() > 1) {
			obj.SetMonth(obj.GetMonth()-1);
			obj.SetDay(obj.GetDIM(obj.GetMonth()));
		}
		else {
			obj.SetMonth(11);
			obj.SetDay(obj.GetDIM(obj.GetMonth()));
			obj.SetYear(obj.GetYear()-1);
		}
	}
	return obj;
}

Date operator--(Date& obj, int) {
	Date temp = obj;
	obj.SetDay(obj.GetDay() - 1);
	if (obj.GetDay() < 1) {
		if (obj.GetMonth() > 1) {
			obj.SetMonth(obj.GetMonth() - 1);
			obj.SetDay(obj.GetDIM(obj.GetMonth()));
		}
		else {
			obj.SetMonth(11);
			obj.SetDay(obj.GetDIM(obj.GetMonth()));
			obj.SetYear(obj.GetYear() - 1);
		}
	}
	return temp;
}

Date operator+(long long a, Date& obj) {
	Date temp = obj + a;
	return temp;
}

Date operator-( Date& obj, long long a) {
	Date temp(obj);
	temp.SetDay(temp.GetDay() - a);
	while (temp.GetDay() < 1) {
		if (temp.GetMonth() > 0) {
			temp.SetMonth(temp.GetMonth() - 1);
		}
		else {
			temp.SetMonth(11);
			temp.SetYear(temp.GetYear()-1);
		}
		temp.CheckLeap();
		temp.SetDay(temp.GetDay() + temp.GetDIM(temp.GetMonth()));
	}
	temp.SetDID();
	return temp;
}

Date operator-(const Date& obj1, const Date& obj2) {
	if (obj1.GetDID() < obj2.GetDID()) {
		cout << "error\n";
		return obj1;
	}
	Date temp;
	temp.ResetDID(obj1.GetDID() - obj2.GetDID());
	if (temp.GetDID() < 0) {
		cout << "error\n";
		Date obj0;
		return obj0;
	}
	temp.ResetDate(temp.GetDID());
	return temp;
}

Date& operator-=(Date& obj, long long a) {
	obj.SetDay(obj.GetDay() - a);
	while (obj.GetDay() < 1) {
		if (obj.GetMonth() > 0) {
			obj.SetMonth(obj.GetMonth()-1);
		}
		else {
			obj.SetMonth(11);
			obj.SetYear(obj.GetYear()-1);
		}
		obj.CheckLeap();
		obj.SetDay(obj.GetDay() + obj.GetDIM(obj.GetMonth()));
	}
	obj.SetDID();
	return obj;
}

Date& operator+=(Date& obj, long long a) {
	obj.SetDay(obj.GetDay() + a);
	obj.CheckLeap();
	while (obj.GetDay() > obj.GetDIM(obj.GetMonth()));
	obj.SetDay(obj.GetDay() - obj.GetDIM(obj.GetMonth()));
	obj.SetMonth(obj.GetMonth() + 1);;
		if (obj.GetMonth() > 11) {
			obj.SetMonth(0);
			obj.SetYear(obj.GetYear()+1);
			obj.CheckLeap();
		}
	obj.SetDefFeb();
	obj.SetDID();
	return obj;
}

bool operator>(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() > obj2.GetDID() ? 1 : 0;
}

bool operator<(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() < obj2.GetDID() ? 1 : 0;
}

bool operator>=(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() >= obj2.GetDID() ? 1 : 0;
}

bool operator<=(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() <= obj2.GetDID() ? 1 : 0;
}

bool operator==(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() == obj2.GetDID() ? 1 : 0;
}

bool operator!=(const Date& obj1, const Date& obj2) {
	return obj1.GetDID() != obj2.GetDID() ? 1 : 0;
}