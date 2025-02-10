// Write a program that checks if a given year is a leap year.

#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if (isLeapYear(year))
    {
        cout << year << " is a leap year.";
    }
    else
    {
        cout << year << " is not a leap year.";
    }
}