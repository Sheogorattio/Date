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
	cout << "DATE: \t" << day << "." << month+1 << "." << year << "\t" << leap_y << "\t" << daysInDate << endl;
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

Date& Date::operator++() {
	++day;
	if (day > daysInMonth[month]) {
		day = 1;
		++month;
	}
	if (month > 11) {
		month = 0;
		++year;
	}

	SetDID();
	return *this;
}

Date Date::operator++(int) {
	Date temp = *this;

	++day;
	if (day > daysInMonth[month]) {
		day = 1;
		++month;
	}
	if (month > 11) {
		month = 0;
		++year;
	}

	SetDID();
	return temp;
}

Date& Date::operator--() {
	--day;
	if (day < 1) {
		if (month > 1) {
			--month;
			day = daysInMonth[month];
		}
		else {
			month = 11;
			day = daysInMonth[month];
			--year;
		}
	}
	SetDID();
	return *this;
}

Date Date::operator--(int) {
	Date temp = *this;

	--day;
	if (day < 1) {
		if (month > 1) {
			--month;
			day = daysInMonth[month];
		}
		else {
			month = 11;
			day = daysInMonth[month];
			--year;
		}
	}

	SetDID();
	return temp;
}

Date Date::operator+(long long a)const {
	Date temp= *this;
	temp.day += a;
	temp.CheckLeap();
	while (temp.day > daysInMonth[temp.month]) { // реализовано добавление бесконечно большого числа(в пределах long long)
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

Date Date::operator-(const Date& obj)const {
	if (year < obj.year) {
		cout << "error\n";
		return *this;
	}
	long long diff = daysInDate - obj.daysInDate;
	Date temp;
	return temp+diff-1;//вычитаетс€ 1 из-за того, что при в конструкторе по умолчанию temp инициализируетс€ одним днЄм (первое €нвар€ нулевого года)
}

Date& Date::operator-=(long long a) {
	day -= a;
	while (day < 1) {
		if (month > 0) {
			month--;
		}
		else {
			month = 11;
			year--;
		}
		CheckLeap();
		day += daysInMonth[month];
	}
	SetDID();
	return *this;
}

Date& Date::operator+=(long long a) {
	day += a;
	CheckLeap();
	while (day > daysInMonth[month]) {
		day -= daysInMonth[month];
		month++;
		if (month > 11) {
			month = 0;
			year++;
			CheckLeap();
		}
	}
	daysInMonth[1] = 28;
	SetDID();
	return *this;
}

bool Date::operator>(const Date& obj)const {
	return daysInDate > obj.daysInDate ? 1 : 0;
}

bool Date::operator<(const Date& obj)const {
	return daysInDate < obj.daysInDate ? 1 : 0;
}

bool Date::operator>=(const Date& obj)const {
	return daysInDate >= obj.daysInDate ? 1 : 0;
}

bool Date::operator<=(const Date& obj)const {
	return daysInDate <= obj.daysInDate ? 1 : 0;
}

bool Date::operator==(const Date& obj)const {
	return daysInDate == obj.daysInDate ? 1 : 0;
}

bool Date::operator!=(const Date& obj)const {
	return daysInDate != obj.daysInDate ? 1 : 0;
}