#include "stdafx.h"
#include "Date_Time.h"

using namespace std;

// Конструктор по умолчание
DateTime::DateTime() {
	DateTime::set_year(2020);
	DateTime::set_month(9);
	DateTime::set_day(20);
	DateTime::set_hours(13);
	DateTime::set_minute(54);
	DateTime::set_second(32);
}
// Перевод в строку
char* DateTime::toString() {
	stringstream MyString_1, MyString_2;
	string ResString_1, ResSrting_2, ResaltStr;
	if(DateTime::get_day() < 10 && DateTime::get_month() < 10)
		MyString_1 << "0" << DateTime::get_day() << ":0" << DateTime::get_month() << ":" << DateTime::get_year();
	else if(DateTime::get_day() < 10 && DateTime::get_month() > 10)
		MyString_1 << "0" << DateTime::get_day() << ":" << DateTime::get_month() << ":" << DateTime::get_year();
	else if (DateTime::get_day() > 10 && DateTime::get_month() < 10)
		MyString_1 << DateTime::get_day() << ":0" << DateTime::get_month() << ":" << DateTime::get_year();
	else
		MyString_1 << DateTime::get_day() << ":" << DateTime::get_month() << ":" << DateTime::get_year();
	if(DateTime::get_hours() < 10 && DateTime::get_minute() < 10 && DateTime::get_second() < 10)
		MyString_2 << "0" << DateTime::get_hours() << ":0" << DateTime::get_minute() << ":0" << DateTime::get_second();
	else if (DateTime::get_hours() > 10 && DateTime::get_minute() < 10 && DateTime::get_second() < 10)
		MyString_2 << DateTime::get_hours() << ":0" << DateTime::get_minute() << ":0" << DateTime::get_second();
	else if (DateTime::get_hours() < 10 && DateTime::get_minute() > 10 && DateTime::get_second() < 10)
		MyString_2 << "0" << DateTime::get_hours() << ":" << DateTime::get_minute() << ":0" << DateTime::get_second();
	else if (DateTime::get_hours() < 10 && DateTime::get_minute() < 10 && DateTime::get_second() > 10)
		MyString_2 << "0" << DateTime::get_hours() << ":0" << DateTime::get_minute() << ":" << DateTime::get_second();
	else if (DateTime::get_hours() > 10 && DateTime::get_minute() > 10 && DateTime::get_second() < 10)
		MyString_2 << DateTime::get_hours() << ":" << DateTime::get_minute() << ":0" << DateTime::get_second();
	else if (DateTime::get_hours() > 10 && DateTime::get_minute() < 10 && DateTime::get_second() > 10)
		MyString_2 << DateTime::get_hours() << ":0" << DateTime::get_minute() << ":" << DateTime::get_second();
	else if (DateTime::get_hours() < 10 && DateTime::get_minute() > 10 && DateTime::get_second() > 10)
		MyString_2 << "0" << DateTime::get_hours() << ":" << DateTime::get_minute() << ":" << DateTime::get_second();
	else
		MyString_2 << DateTime::get_hours() << ":" << DateTime::get_minute() << ":" << DateTime::get_second();
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
void DateTime::Reduce_year() { 
	DateTime::set_year(DateTime::get_year() - 1);
}
void DateTime::Enlarge_year() {
	DateTime::set_year(DateTime::get_year() + 1);
}
void DateTime::Reduce_month() {
	if (DateTime::get_month() - 1 < 1) {
		DateTime::set_month(12);
		DateTime::Reduce_year();
	}
	else
		DateTime::set_month(DateTime::get_month() - 1);
}
void DateTime::Enlarge_month() {
	if (DateTime::get_month() + 1 > 12) {
		DateTime::set_month(1);
		DateTime::Enlarge_year();
	}
	else
		DateTime::set_month(DateTime::get_month() + 1);
}
void DateTime::Reduce_day() {
	if (DateTime::get_day() - 1 < 1) {
		DateTime::set_day(31);
		DateTime::Reduce_month();
	}
	else
		DateTime::set_day(DateTime::get_day() - 1);
}
void DateTime::Enlarge_day() {
	if (DateTime::get_day() + 1 > 31) {
		DateTime::set_day(1);
		DateTime::Enlarge_month();
	}
	else
		DateTime::set_day(DateTime::get_day() + 1);
}
void DateTime::Reduce_hours() {
	if (DateTime::get_hours() - 1 < 0) {
		DateTime::set_hours(23);
		DateTime::Reduce_day();
	}
	else
		DateTime::set_hours(DateTime::get_hours() - 1);
}
void DateTime::Enlarge_hours(){
	if (DateTime::get_hours() + 1 > 24) {
		DateTime::set_hours(0);
		DateTime::Enlarge_day();
	}
	else
		DateTime::set_hours(DateTime::get_hours() + 1);
}
void DateTime::Reduce_minute() {
	if (DateTime::get_minute() - 1 < 0) {
		DateTime::set_minute(59);
		DateTime::Reduce_hours();
	}
	else
		DateTime::set_minute(DateTime::get_minute() - 1);
}
void DateTime::Enlarge_minute() {
	if (DateTime::get_minute() + 1 > 60) {
		DateTime::set_minute(0);
		DateTime::Enlarge_hours();
	}
	else
		DateTime::set_minute(DateTime::get_minute() + 1);
}
void DateTime::Reduce_second() {
	if (DateTime::get_second() - 1 < 0) {
		DateTime::set_minute(59);
		DateTime::Reduce_minute();
	}
	else
		DateTime::set_second(DateTime::get_second() - 1);
}
void DateTime::Enlarge_second() {
	if (DateTime::get_second() + 1 > 60) {
		DateTime::set_second(0);
		DateTime::Enlarge_minute();
	}
	else
		DateTime::set_second(DateTime::get_second() + 1);
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
void DateTime::set_year(int _year) {
	if (_year < 10000 && _year > 999)
		year = _year;
	else
		year = 2020;
}
void DateTime::set_month(int _month) {
	if (_month > 0 && _month < 13)
		month = _month;
	else
		month = 9;
}
void DateTime::set_day(int _day) {
	if (_day > 0 && _day < 32)
		day = _day;
	else
		day = 20;
}
void DateTime::set_hours(int _hours) {
	if (_hours > -1 && _hours < 24)
		hours = _hours;
	else
		hours = 12;
}
void DateTime::set_minute(int _minute) {
	if (_minute > -1 && _minute < 60)
		minute = _minute;
	else
		minute = 0;
}
void DateTime::set_second(int _second) {
	if (_second > -1 && _second < 60)
		second = _second;
	else
		second = 0;
}


