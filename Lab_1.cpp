#include "stdafx.h"
#include "Date_Time.h"

using namespace std;

void Test() {
	DateTime today;
	srand(time(NULL));
	int month = 0, day = 0, hours = 0, minute = 0, second = 0;
	cout << "----------------------------------------------------------------" << endl;
	cout << today.tostring() << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < rand() % 10; i++)
	{
		today.enlarge_month();
		cout << today.tostring() << endl;
		month++;
	}
	for (int i = 0; i < rand() % 30; i++)
	{
		today.reduce_day();
		cout << today.tostring() << endl;
		day++;
	}
	for (int i = 0; i < rand() % 24; i++)
	{
		today.enlarge_hours();
		cout << today.tostring() << endl;
		hours++;
	}
	for (int i = 0; i < rand() % 59; i++)
	{
		today.enlarge_minute();
		cout << today.tostring() << endl;
		minute++;
	}
	for (int i = 0; i < rand() % 59; i++)
	{
		today.reduce_second();
		cout << today.tostring() << endl;
		second++;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << "Ours resalt: " << today.tostring() << endl;
	cout << "iterations = " << today.iterations << endl;
	cout << "month + 1*" << month << endl;
	cout << "hours + 1*" << hours << endl;
	cout << "minute + 1*" << minute << endl;
	cout << "second + 1*" << second << endl;
}


int main()
{
	Test();
	return 0;
}

