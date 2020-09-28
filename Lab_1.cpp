#include "stdafx.h"
#include "Date_Time.h"

using namespace std;

void Test() {
	DateTime today;
	srand(time(NULL));
	int month = 0, day = 0, hours = 0, minute = 0, second = 0;
	cout << "----------------------------------------------------------------" << endl;
	cout << today.toString() << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < rand() % 10; i++)
	{
		today.Enlarge_month();
		cout << today.toString() << endl;
		month++;
	}
	for (int i = 0; i < rand() % 30; i++)
	{
		today.Reduce_day();
		cout << today.toString() << endl;
		day++;
	}
	for (int i = 0; i < rand() % 24; i++)
	{
		today.Enlarge_hours();
		cout << today.toString() << endl;
		hours++;
	}
	for (int i = 0; i < rand() % 59; i++)
	{
		today.Enlarge_minute();
		cout << today.toString() << endl;
		minute++;
	}
	for (int i = 0; i < rand() % 59; i++)
	{
		today.Reduce_second();
		cout << today.toString() << endl;
		second++;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << "Ours resalt: " << today.toString() << endl;
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

