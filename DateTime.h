#pragma once

class DateTime
{
public:
	DateTime();
	DateTime(int day, int month, int year, int hours, int minute, int  second);
	DateTime(const DateTime& object);
	DateTime& operator = (const DateTime& object);
	char* toString();
	char* toString(char* array, const int size);
	void reduceYear(); // year - 1
	void reduceYear(int number); // year - number
	void enlargeYear(); // year + 1
	void enlargeYear(int number); // year + number
	void reduceMonth(); // month - 1
	void reduceMonth(int number); // month - number
	void enlargeMonth(); // month + 1
	void enlargeMonth(int number); // month + number
	void reduceDay(); // day - 1
	void reduceDay(int number); // day - number
	void enlargeDay(); // day + 1
	void enlargeDay(int number); // day + number
	void reduceHours(); // hours - 1
	void reduceHours(int number); // hours - number
	void enlargeHours(); // hours + 1
	void enlargeHours(int number); // hours + number
	void reduceMinute(); // minute - 1
	void reduceMinute(int number); // minute - number
	void enlargeMinute(); // minute + 1
	void enlargeMinute(int number); // minute + number
	void reduceSecond(); // second - 1
	void reduceSecond(int number); // second - number
	void enlargeSecond(); // second + 1
	void enlargeSecond(int number); // second + number
	// Get and Set
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHours(int hours);
	void setMinute(int minute);
	void setSecond(int second);
	int getYear();
	int getMonth();
	int getDay();
	int getHours();
	int getMinute();
	int getSecond();
	static int iterations;
private:
	int year, month, day, hours, minute, second;
	bool leapYear(int year);
	bool checkMonth(int month);
};
