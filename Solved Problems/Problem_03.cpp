// Write a program that takes three numbers as input and outputs the largest one.

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter three numbers (ex: 10 20 30): ";
    cin >> a >> b >> c;

    if (a > b && a > c)
    {
        cout << a << " is greater then into " << b << ", " << c;
    }
    else if (b > a && b > c)
    {
        cout << b << " is greater then into " << a << ", " << c;
    }
    else
    {
        cout << c << " is greater then into " << a << ", " << b;
    }
    return 0;
}
