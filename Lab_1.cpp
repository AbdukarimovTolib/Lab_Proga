#include "stdafx.h"
#include "Date_Time.h"

using namespace std;

void Test() {
	DateTime today;
	cout << "" << endl;
	cout << today.tostring() << endl;
	cout << "day + 1" << endl;
	cout << "Expected Result: 01:01:2021     13:45:32" << endl;
	today.enlarge_day();
	cout << "Result: " << today.tostring() << endl;
	today.set_year(2020);
	today.set_day(29);
	today.set_month(2);
	cout << "--------------------------\n" << today.tostring() << "\n" << "day + 1" << endl;
	cout << "Expected Result: 01:03:2020     13:45:32" << endl;
	today.enlarge_day();
	cout << "Result: " << today.tostring() << endl;
	today.set_year(2022);
	today.set_day(1);
	today.set_month(3);
	cout << "--------------------------\n" << today.tostring() << "\n" << "day - 1" << endl;
	today.reduce_day();
	cout << "Expected Result: 28:02:2022     13:45:32" << endl;
	cout << "Result: " << today.tostring() << endl;
	today.set_year(2022);
	today.set_day(1);
	today.set_month(8);
	cout << "--------------------------\n" << today.tostring() << "\n" << "day - 1" << endl;
	today.reduce_day();
	cout << "Expected Result: 31:07:2022     13:45:32" << endl;
	cout << "Result: " << today.tostring() << endl;
	cout << "put inappropriate numbers day = 57 and month = 17" << endl;
	today.set_day(57);
	today.set_month(17);
}

int main()
{
	Test();
	return 0;
}

