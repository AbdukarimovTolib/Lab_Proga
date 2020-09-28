#pragma once
#include "stdafx.h"

using namespace std;

class Date_Time
{
	int year, month, day, hours, minute, second;
public:
	Date_Time();
	char* toString();
	void Reduce_year(); // year - 1
	void Enlarge_year(); // year + 1
	void Reduce_month(); // month - 1
	void Enlarge_month(); // month + 1
	void Reduce_day(); // day - 1
	void Enlarge_day(); // day + 1
	void Reduce_hours(); // hours - 1
	void Enlarge_hours(); // hours + 1
	void Reduce_minute(); // minute - 1
	void Enlarge_minute(); // minute + 1
	void Reduce_second(); // second - 1
	void Enlarge_second(); // second + 1
	void set_year(int _year);
	void set_month(int _month);
	void set_day(int _day);
	void set_hours(int _hours);
	void set_minute(int _minute);
	void set_second(int _second);
	int get_year();
	int get_month();
	int get_day();
	int get_hours();
	int get_minute();
	int get_second();
};



