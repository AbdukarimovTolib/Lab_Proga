#include "stdafx.h"
#include "Date_Time.h"

using namespace std;


int DateTime::iterations = 0;

// Конструктор по умолчание
DateTime::DateTime() {
	DateTime::set_year(2020);
	DateTime::set_month(9);
	DateTime::set_day(20);
	DateTime::set_hours(13);
	DateTime::set_minute(54);
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
// Перевод в строку
char* DateTime::tostring() {
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
	if (DateTime::get_day() - 1 < 1) {
		DateTime::set_day(31);
		DateTime::reduce_month();
	}
	else
		DateTime::set_day(DateTime::get_day() - 1);
	iterations++;
}
void DateTime::enlarge_day() {
	if (DateTime::get_day() + 1 > 31) {
		DateTime::set_day(1);
		DateTime::enlarge_month();
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
		this->year = 2020;
}
void DateTime::set_month(int month) {
	if (month > 0 && month < 13)
		this->month = month;
	else
		this->month = 9;
}
void DateTime::set_day(int day) {
	if (day > 0 && day < 32)
		this->day = day;
	else
		this->day = 20;
}
void DateTime::set_hours(int hours) {
	if (hours > -1 && hours < 24)
		this->hours = hours;
	else
		this->hours = 12;
}
void DateTime::set_minute(int minute) {
	if (minute > -1 && minute < 60)
		this->minute = minute;
	else
		this->minute = 0;
}
void DateTime::set_second(int second) {
	if (second > -1 && second < 60)
		this->second = second;
	else
		this->second = 0;
}


