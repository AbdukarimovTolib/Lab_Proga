#pragma once
#include "stdafx.h"

using namespace std;

class DateTime
{
public:
	DateTime();
	DateTime(int day, int month, int year, int hours, int minute, int  second);
	char* tostring();
	void reduce_year(); // year - 1
	void enlarge_year(); // year + 1
	void reduce_month(); // month - 1
	void enlarge_month(); // month + 1
	void reduce_day(); // day - 1
	void enlarge_day(); // day + 1
	void reduce_hours(); // hours - 1
	void enlarge_hours(); // hours + 1
	void reduce_minute(); // minute - 1
	void enlarge_minute(); // minute + 1
	void reduce_second(); // second - 1
	void enlarge_second(); // second + 1
	void set_year(int year);
	void set_month(int month);
	void set_day(int day);
	void set_hours(int hours);
	void set_minute(int minute);
	void set_second(int second);
	int get_year();
	int get_month();
	int get_day();
	int get_hours();
	int get_minute();
	int get_second();
	static int iterations;
private:
	int year, month, day, hours, minute, second;
};



