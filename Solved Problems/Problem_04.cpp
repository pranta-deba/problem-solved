// Write a program to find the smallest of three numbers.

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter three numbers (ex: 10 20 30): ";
    cin >> a >> b >> c;

    if (a < b && a < c)
    {
        cout << a << " is less then into " << b << ", " << c;
    }
    else if (b < a && b < c)
    {
        cout << b << " is less then into " << a << ", " << c;
    }
    else
    {
        cout << c << " is less then into " << a << ", " << b;
    }
    return 0;
}
