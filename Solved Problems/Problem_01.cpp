// Compare Two Numbers: Write a program that compares two numbers and prints which one is larger or if they are equal.

#include <iostream>
using namespace std;

int main()
{
    int a = 20, b = 22;
    if (a < b && b > a)
    {
        cout << b << " is greater then " << a;
    }
    else if (a == b)
    {
        cout << a << " & " << b << " are equals";
    }
    else
    {
        cout << a << " is greater then " << b;
    }

    return 0;
}
