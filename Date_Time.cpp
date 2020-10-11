#include "stdafx.h"
#include "Date_Time.h"

using namespace std;


int DateTime::iterations = 0;

// Конструктор по умолчание
DateTime::DateTime() {
	DateTime::set_year(2020);
	DateTime::set_month(12);
	DateTime::set_day(31);
	DateTime::set_hours(13);
	DateTime::set_minute(45);
	DateTime::set_second(32);
}
DateTime::DateTime(int day, int month, int year, int hours, int minute, int  second) {
	DateTime::set_year(year);
	DateTime::set_month(month);
	DateTime::set_day(day);
	DateTime::set_hours(hours);
	DateTime::set_minute(minute);
	DateTime::set_second(second);
}
//Проверка високосного года 1-leap year and 0-not leap year
bool DateTime::leapyear(int year) {
	if (year % 4 == 0 (year % 100 !=0 || year % 400 == 0))
		return 1;
	else
		return 0;
}
// Проверка месяца 1-31 day and 0-30 day
bool DateTime::checkmonth(int month) {
	if (month == 2) {
		cout << "Eror!" << endl;
	}
	else {
		if (month <= 7 && month % 2 != 0)
			return 1;
		if (month <= 7 && month % 2 == 0 && month != 2)
			return 0;
		if (month > 7 && month % 2 == 0)
			return 1;
		if (month > 7 && month % 2 != 0)
			return 0;
	}
}
// Перевод в строку
char* DateTime::tostring() {
	char adate[5], ayear[5], amonth[5], ahours[5], aminute[5], asecond[5];
	int ysize = 0, size = 0;
	if (DateTime::get_year() > 999 && DateTime::get_year() < 10000) {
		ayear[0] = DateTime::get_year() / 1000 + '0';
		ayear[1] = (DateTime::get_year() / 100) % 10 + '0';
		ayear[2] = (DateTime::get_year() / 10) % 10 + '0';
		ayear[3] = DateTime::get_year() % 10 + '0';
		ysize += 4;
	}
	if (DateTime::get_year() > 99 && DateTime::get_year() < 1000)
	{
		ayear[0] = DateTime::get_year() / 100 + '0';
		ayear[1] = (DateTime::get_year() / 10) % 10 + '0';
		ayear[2] = DateTime::get_year() % 10 + '0';
		ysize += 3;
	}
	if (DateTime::get_day() > 9) {
		adate[0] = DateTime::get_day() / 10 + '0';
		adate[1] = DateTime::get_day() % 10 + '0';
	}
	else {
		adate[0] = '0';
		adate[1] = DateTime::get_day() + '0';
	}
	if (DateTime::get_month() > 9) {
		amonth[0] = DateTime::get_month() / 10 + '0';
		amonth[1] = DateTime::get_month() % 10 + '0';
	}
	else {
		amonth[0] = '0';
		amonth[1] = DateTime::get_month() + '0';
	}
	if (DateTime::get_hours() > 9) {
		ahours[0] = DateTime::get_hours() / 10 + '0';
		ahours[1] = DateTime::get_hours() % 10 + '0';
	}
	else{
		ahours[0] = '0';
		ahours[1] = DateTime::get_hours() + '0';
	}
	if (DateTime::get_minute() > 9) {
		aminute[0] = DateTime::get_minute() / 10 + '0';
		aminute[1] = DateTime::get_minute() % 10 + '0';
	}
	else {
		aminute[0] = '0';
		aminute[1] = DateTime::get_minute() + '0';
	}
	if (DateTime::get_second() > 9) {
		asecond[0] = DateTime::get_second() / 10 + '0';
		asecond[1] = DateTime::get_second() % 10 + '0';
	}
	else {
		asecond[0] = '0';
		asecond[1] = DateTime::get_second() + '0';
	}
	size = ysize + 10;
	char* resChar = new char[size + 6];
	for (int i = 0; i < 2; i++)
		resChar[i] = adate[i];
	resChar[2] = ':';
	for (int i = 0; i < 2; i++)
		resChar[i + 3] = amonth[i];
	resChar[5] = ':';
	for (int i = 0; i < ysize; i++)
		resChar[i + 6] = ayear[i];
	resChar[6 + ysize] = '\t';
	for (int i = 0; i < 2; i++)
		resChar[i + ysize + 7] = ahours[i];
	resChar[9 + ysize] = ':';
	for (int i = 0; i < 2; i++)
		resChar[i + ysize + 10] = aminute[i];
	resChar[ysize + 12] = ':';
	for (int i = 0; i < 2; i++)
		resChar[ysize + 13 + i] = asecond[i];
	resChar[size + 6 - 1] = '\0';
	return resChar;
}
// уменьшение или увелечение значение!
void DateTime::reduce_year() { 
	DateTime::set_year(DateTime::get_year() - 1);
	iterations++;
}
void DateTime::enlarge_year() {
	DateTime::set_year(DateTime::get_year() + 1);
	iterations++;
}
void DateTime::reduce_month() {
	if (DateTime::get_month() - 1 < 1) {
		DateTime::set_month(12);
		DateTime::reduce_year();
	}
	else
		DateTime::set_month(DateTime::get_month() - 1);
	iterations++;
}
void DateTime::enlarge_month() {
	if (DateTime::get_month() + 1 > 12) {
		DateTime::set_month(1);
		DateTime::enlarge_year();
	}
	else
		DateTime::set_month(DateTime::get_month() + 1);
	iterations++;
}
void DateTime::reduce_day() {
	if (DateTime::get_day() == 1) {
		if (DateTime::get_month() == 3) {
			if (leapyear(DateTime::get_year())) {
				DateTime::set_day(29);
				DateTime::reduce_month();
			}
			else {
				DateTime::set_day(28);
				DateTime::reduce_month();
			}
		}
		else if (DateTime::checkmonth(DateTime::get_month())) {
			DateTime::set_day(31);
			DateTime::reduce_month();
		}
		else {
			DateTime::set_day(30);
			DateTime::reduce_month();
		}
	}
	else if (DateTime::get_day() != 1) {
		DateTime::set_day(DateTime::get_day() - 1);
	}
	iterations++;
}
void DateTime::enlarge_day() {
	if (DateTime::get_day() == 28 && DateTime::get_month() == 2) {
		if (!leapyear(DateTime::get_year())) {
			DateTime::set_day(1);
			DateTime::enlarge_month();
		}
	}
	else if (DateTime::get_day() == 29 && DateTime::get_month() == 2) {
		if (leapyear(DateTime::get_year())) {
			DateTime::set_day(1);
			DateTime::enlarge_month();
		}
	}
	else if (DateTime::get_day() == 30) {
		if (!DateTime::checkmonth(DateTime::get_month())) {
			DateTime::set_day(1);
			DateTime::enlarge_month();
		}
	}
	else if (DateTime::get_day() == 31) {
		if (DateTime::checkmonth(DateTime::get_month())) {
			DateTime::set_day(1);
			DateTime::enlarge_month();
		}
	}
	else
		DateTime::set_day(DateTime::get_day() + 1);
	iterations++;
}
void DateTime::reduce_hours() {
	if (DateTime::get_hours() - 1 < 0) {
		DateTime::set_hours(23);
		DateTime::reduce_day();
	}
	else
		DateTime::set_hours(DateTime::get_hours() - 1);
	iterations++;
}
void DateTime::enlarge_hours(){
	if (DateTime::get_hours() + 1 > 24) {
		DateTime::set_hours(0);
		DateTime::enlarge_day();
	}
	else
		DateTime::set_hours(DateTime::get_hours() + 1);
	iterations++;
}
void DateTime::reduce_minute() {
	if (DateTime::get_minute() - 1 < 0) {
		DateTime::set_minute(59);
		DateTime::reduce_hours();
	}
	else
		DateTime::set_minute(DateTime::get_minute() - 1);
	iterations++;
}
void DateTime::enlarge_minute() {
	if (DateTime::get_minute() + 1 > 60) {
		DateTime::set_minute(0);
		DateTime::enlarge_hours();
	}
	else
		DateTime::set_minute(DateTime::get_minute() + 1);
	iterations++;
}
void DateTime::reduce_second() {
	if (DateTime::get_second() - 1 < 0) {
		DateTime::set_minute(59);
		DateTime::reduce_minute();
	}
	else
		DateTime::set_second(DateTime::get_second() - 1);
	iterations++;
}
void DateTime::enlarge_second() {
	if (DateTime::get_second() + 1 > 60) {
		DateTime::set_second(0);
		DateTime::enlarge_minute();
	}
	else
		DateTime::set_second(DateTime::get_second() + 1);
	iterations++;
}
// Геттеры и Сеттеры для полей класса  
int DateTime::get_day() {
	return day;
}
int DateTime::get_year() {
	return year;
}
int DateTime::get_month() {
	return month;
}
int DateTime::get_hours() {
	return hours;
}
int DateTime::get_minute() {
	return minute;
}
int DateTime::get_second() {
	return second;
}
void DateTime::set_year(int year) {
	if (year < 10000 && year > 999)
		this->year = year;
	else
		cout << "Error! Invalid number" << endl;
}
void DateTime::set_month(int month) {
	if (month > 0 && month < 13)
		this->month = month;
	else
		cout << "Error! Invalid number" << endl;
}
void DateTime::set_day(int day) {
	if (day > 0 && day < 32) {
		if (DateTime::get_month() == 2) {
			if (leapyear(DateTime::get_year())) {
				if (day < 30)
					this->day = day;
				else
					cout << "Error! Invalid number" << endl;
			}
			else {
				if (day < 29)
					this->day = day;
				else
					cout << "Error! Invalid number" << endl;
			}
		}
		else {
			if (DateTime::checkmonth(DateTime::get_month())) {
					this->day = day;
			}
			else {
				if(day < 31)
					this->day = day;
				else
					cout << "Error! Invalid number" << endl;
			}
		}
	}
	else
		cout << "Error! Invalid number" << endl;
}
void DateTime::set_hours(int hours) {
	if (hours > -1 && hours < 24)
		this->hours = hours;
	else
		cout << "Error! Invalid number" << endl;
}
void DateTime::set_minute(int minute) {
	if (minute > -1 && minute < 60)
		this->minute = minute;
	else
		cout << "Error! Invalid number" << endl;
}
void DateTime::set_second(int second) {
	if (second > -1 && second < 60)
		this->second = second;
	else
		cout << "Error! Invalid number" << endl;
}


