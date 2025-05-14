// C++ program for factorial of a number
#include <iostream>
using namespace std;

// function to find factorial of given number
int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Driver code
int main()
{
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}