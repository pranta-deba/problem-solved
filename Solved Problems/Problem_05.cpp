// Sum of First N Numbers: Write a program that finds the sum of the first N natural numbers.

#include <iostream>
using namespace std;

int main()
{
    int N, sum = 0;
    cout << "Enter N: ";
    cin >> N;

    if (N > 0)
    {
        for (int i = 1; i <= N; i++)
        {
            sum += i;
        }
        cout << "Sum of the first " << N << " natural numbers: " << sum;
    }
    else
    {
        cout << "\nEnter a valid number!";
    }
    return 0;
}
