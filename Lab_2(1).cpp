// Eror 111 - inappropriate number or expression

#include <iostream>
#include "DateTime.h"

using namespace std;

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

bool testoperatorminusdatetime() {
    DateTime today(11, 3, 2016, 8, 19, 33), tomorrow(3, 8, 2122, 11, 21, 19);
    cout << "today: " << today.toString() << endl;
    cout << "tomorrow: " << tomorrow.toString() << endl;
    cout << (tomorrow.operator-(today)).toString() << endl;
    return 1;
}

bool testoperatorplusdatetime() {
    DateTime today(11, 3, 2016, 8, 19, 33), tomorrow(3, 8, 2022, 11, 21, 19);
    cout << "today: " << today.toString() << endl;
    cout << "tomorrow: " << tomorrow.toString() << endl;
    cout << (today.operator+(tomorrow)).toString() << endl;
    if (today.operator+(tomorrow).getYear() == 2016 + 2020) {
        return 1;
    }
    else {
        return 0;
    }
    
}

bool testoperatorplusday() {
    DateTime today;
    cout << today.toString() << endl;
    int day = today.getDay();
    today += 5;
    cout << "day + 5" << endl;
    cout << today.toString() << endl;
    if (day + 5 == today.getDay()) {
        return 1;
    }
    else {
        return 0;
    }
}

bool testoperatorminushours() {
    DateTime today(3, 8, 2022, 11, 21, 19);
    cout << today.toString() << endl;
    today = today - 12;
    cout << "hours - 12" << endl;
    cout << today.toString() << endl;
    if (today.getHours() == 23) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    DateTime today;
    cout << today.toString() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatoroverload: " << testoperatoroverload() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatorplusdatetime: " << testoperatorplusdatetime() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatorplusday: " << testoperatorplusday() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatorminushours: " << testoperatorminushours() << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "testoperatorminusdatetime: " << testoperatorminusdatetime() << endl;
    return 0;
}