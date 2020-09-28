#include "stdafx.h"
#include "Date_Time.h"

using namespace std;

// Конструктор по умолчание
Date_Time::Date_Time() {
	Date_Time::set_year(2020);
	Date_Time::set_month(9);
	Date_Time::set_day(20);
	Date_Time::set_hours(13);
	Date_Time::set_minute(54);
	Date_Time::set_second(32);
}
// Перевод в строку
char* Date_Time::toString() {
	stringstream MyString_1, MyString_2;
	string ResString_1, ResSrting_2, ResaltStr;
	if(Date_Time::get_day() < 10 && Date_Time::get_month() < 10)
		MyString_1 << "0" << Date_Time::get_day() << ":0" << Date_Time::get_month() << ":" << Date_Time::get_year();
	else if(Date_Time::get_day() < 10 && Date_Time::get_month() > 10)
		MyString_1 << "0" << Date_Time::get_day() << ":" << Date_Time::get_month() << ":" << Date_Time::get_year();
	else if (Date_Time::get_day() > 10 && Date_Time::get_month() < 10)
		MyString_1 << Date_Time::get_day() << ":0" << Date_Time::get_month() << ":" << Date_Time::get_year();
	else
		MyString_1 << Date_Time::get_day() << ":" << Date_Time::get_month() << ":" << Date_Time::get_year();
	if(Date_Time::get_hours() < 10 && Date_Time::get_minute() < 10 && Date_Time::get_second() < 10)
		MyString_2 << "0" << Date_Time::get_hours() << ":0" << Date_Time::get_minute() << ":0" << Date_Time::get_second();
	else if (Date_Time::get_hours() > 10 && Date_Time::get_minute() < 10 && Date_Time::get_second() < 10)
		MyString_2 << Date_Time::get_hours() << ":0" << Date_Time::get_minute() << ":0" << Date_Time::get_second();
	else if (Date_Time::get_hours() < 10 && Date_Time::get_minute() > 10 && Date_Time::get_second() < 10)
		MyString_2 << "0" << Date_Time::get_hours() << ":" << Date_Time::get_minute() << ":0" << Date_Time::get_second();
	else if (Date_Time::get_hours() < 10 && Date_Time::get_minute() < 10 && Date_Time::get_second() > 10)
		MyString_2 << "0" << Date_Time::get_hours() << ":0" << Date_Time::get_minute() << ":" << Date_Time::get_second();
	else if (Date_Time::get_hours() > 10 && Date_Time::get_minute() > 10 && Date_Time::get_second() < 10)
		MyString_2 << Date_Time::get_hours() << ":" << Date_Time::get_minute() << ":0" << Date_Time::get_second();
	else if (Date_Time::get_hours() > 10 && Date_Time::get_minute() < 10 && Date_Time::get_second() > 10)
		MyString_2 << Date_Time::get_hours() << ":0" << Date_Time::get_minute() << ":" << Date_Time::get_second();
	else if (Date_Time::get_hours() < 10 && Date_Time::get_minute() > 10 && Date_Time::get_second() > 10)
		MyString_2 << "0" << Date_Time::get_hours() << ":" << Date_Time::get_minute() << ":" << Date_Time::get_second();
	else
		MyString_2 << Date_Time::get_hours() << ":" << Date_Time::get_minute() << ":" << Date_Time::get_second();
	MyString_1 >> ResString_1;
	MyString_2 >> ResSrting_2;
	ResaltStr = ResString_1 + '\t' + ResSrting_2;
	char* ResChar = new char[ResaltStr.length() + 1];
	for (int i = 0; i < ResaltStr.length(); i++)
		ResChar[i] = ResaltStr[i];
	ResChar[ResaltStr.length()] = '\0';
	return ResChar;
}
// уменьшение или увелечение значение!
void Date_Time::Reduce_year() { 
	Date_Time::set_year(Date_Time::get_year() - 1);
}
void Date_Time::Enlarge_year() {
	Date_Time::set_year(Date_Time::get_year() + 1);
}
void Date_Time::Reduce_month() {
	if (Date_Time::get_month() - 1 < 1) {
		Date_Time::set_month(12);
		Date_Time::Reduce_year();
	}
	else
		Date_Time::set_month(Date_Time::get_month() - 1);
}
void Date_Time::Enlarge_month() {
	if (Date_Time::get_month() + 1 > 12) {
		Date_Time::set_month(1);
		Date_Time::Enlarge_year();
	}
	else
		Date_Time::set_month(Date_Time::get_month() + 1);
}
void Date_Time::Reduce_day() {
	if (Date_Time::get_day() - 1 < 1) {
		Date_Time::set_day(31);
		Date_Time::Reduce_month();
	}
	else
		Date_Time::set_day(Date_Time::get_day() - 1);
}
void Date_Time::Enlarge_day() {
	if (Date_Time::get_day() + 1 > 31) {
		Date_Time::set_day(1);
		Date_Time::Enlarge_month();
	}
	else
		Date_Time::set_day(Date_Time::get_day() + 1);
}
void Date_Time::Reduce_hours() {
	if (Date_Time::get_hours() - 1 < 0) {
		Date_Time::set_hours(23);
		Date_Time::Reduce_day();
	}
	else
		Date_Time::set_hours(Date_Time::get_hours() - 1);
}
void Date_Time::Enlarge_hours(){
	if (Date_Time::get_hours() + 1 > 24) {
		Date_Time::set_hours(0);
		Date_Time::Enlarge_day();
	}
	else
		Date_Time::set_hours(Date_Time::get_hours() + 1);
}
void Date_Time::Reduce_minute() {
	if (Date_Time::get_minute() - 1 < 0) {
		Date_Time::set_minute(59);
		Date_Time::Reduce_hours();
	}
	else
		Date_Time::set_minute(Date_Time::get_minute() - 1);
}
void Date_Time::Enlarge_minute() {
	if (Date_Time::get_minute() + 1 > 60) {
		Date_Time::set_minute(0);
		Date_Time::Enlarge_hours();
	}
	else
		Date_Time::set_minute(Date_Time::get_minute() + 1);
}
void Date_Time::Reduce_second() {
	if (Date_Time::get_second() - 1 < 0) {
		Date_Time::set_minute(59);
		Date_Time::Reduce_minute();
	}
	else
		Date_Time::set_second(Date_Time::get_second() - 1);
}
void Date_Time::Enlarge_second() {
	if (Date_Time::get_second() + 1 > 60) {
		Date_Time::set_second(0);
		Date_Time::Enlarge_minute();
	}
	else
		Date_Time::set_second(Date_Time::get_second() + 1);
}
// Геттеры и Сеттеры для полей класса  
int Date_Time::get_day() {
	return day;
}
int Date_Time::get_year() {
	return year;
}
int Date_Time::get_month() {
	return month;
}
int Date_Time::get_hours() {
	return hours;
}
int Date_Time::get_minute() {
	return minute;
}
int Date_Time::get_second() {
	return second;
}
void Date_Time::set_year(int _year) {
	if (_year < 10000 && _year > 999)
		year = _year;
	else
		year = 2020;
}
void Date_Time::set_month(int _month) {
	if (_month > 0 && _month < 13)
		month = _month;
	else
		month = 9;
}
void Date_Time::set_day(int _day) {
	if (_day > 0 && _day < 32)
		day = _day;
	else
		day = 20;
}
void Date_Time::set_hours(int _hours) {
	if (_hours > -1 && _hours < 24)
		hours = _hours;
	else
		hours = 12;
}
void Date_Time::set_minute(int _minute) {
	if (_minute > -1 && _minute < 60)
		minute = _minute;
	else
		minute = 0;
}
void Date_Time::set_second(int _second) {
	if (_second > -1 && _second < 60)
		second = _second;
	else
		second = 0;
}


