// Eror 111 - inappropriate number or expression

#include <iostream>
#include "DateTime.h"

using namespace std;

bool testTostringoverload() {
    DateTime today;
    const int size = 2;
    int check = today.getDay() / 10;
    char* array = new char[size];
    cout << today.toString(array, size);
    if (array[0] == check) {
        return 1;
    }
    else {
        return 0;
    }
}

bool testReducemonthoverload() {
    DateTime today;
    int year = today.getYear();
    cout << today.toString() << endl;
    int number = 53;
    cout << "month - " << number << endl;
    today.reduceMonth(number);
    cout << today.toString() << endl;
    if (today.getYear() == year - number / 12) {
        return 1;
    }
    else {
        return 0;
    }
}

bool testEnlargedayoverload() {
    DateTime today;
    cout << today.toString() << endl;
    int number = 742;
    today.enlargeDay(number);
    cout << "day + " << number << endl;
    cout << today.toString() << endl;
    return 0;
}

bool testoperatoroverload() {
    DateTime today(18, 5, 2011, 11, 4, 44), tomorrow(11, 8, 2015, 16, 44, 54), evenings;
    cout << "today: " << today.toString() << endl;
    cout << "tomorrow: " << tomorrow.toString() << endl;
    cout << "evenings: " << evenings.toString() << endl;
    today = evenings = tomorrow;
    cout << "\tafter\t" << endl;
    cout << "today: " << today.toString() << endl;
    cout << "tomorrow: " << tomorrow.toString() << endl;
    cout << "evenings: " << evenings.toString() << endl;
    if (today.getMonth() == tomorrow.getMonth() && evenings.getHours() == tomorrow.getHours()) {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    DateTime today;
    cout << today.toString() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testTostringoverload: " << testTostringoverload() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testReducemonthoverload: " << testReducemonthoverload() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testEnlargedayoverload: " << testEnlargedayoverload() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatoroverload: " << testoperatoroverload() << endl;
    return 0;
}