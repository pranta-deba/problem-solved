// C++ program to determine whether
// the number is Armstrong number or not
#include <bits/stdc++.h>
using namespace std;

// Function to calculate x raised
// to the power y
int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    return x * power(x, y / 2) * power(x, y / 2);
}

/* Function to calculate order of the number */
int order(int x)
{
    int n = 0;
    while (x)
    {
        n++;
        x = x / 10;
    }
    return n;
}

// Function to check whether the given
// number is Armstrong number or not
bool isArmstrong(int x)
{
    // Calling order function
    int n = order(x);
    int temp = x, sum = 0;
    while (temp)
    {
        int r = temp % 10;
        sum += power(r, n);
        temp = temp / 10;
    }

    // If satisfies Armstrong condition
    return (sum == x);
}

// Driver Code
int main()
{
    int x = 153;
    cout << boolalpha << isArmstrong(x) << endl;
    x = 1253;
    cout << boolalpha << isArmstrong(x) << endl;
    return 0;
}