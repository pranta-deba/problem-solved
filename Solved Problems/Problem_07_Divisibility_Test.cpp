// Divisibility Test: Check whether a number is divisible by both 3 and 5.

#include <iostream>
using namespace std;

bool isDivisibleByBoth(int num)
{
    return (num % 3 == 0 && num % 5 == 0);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isDivisibleByBoth(num))
    {
        cout << num << " is divisible by both 3 and 5.";
    }
    else
    {
        cout << num << " is not divisible by both 3 and 5.";
    }

    return 0;
}