// Greater of Two Numbers (Using Functions): Create a function that takes two numbers as input and returns the greater one.

#include <iostream>
#include <vector>

using namespace std;

int findGreater(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int main()
{
    int number1, number2;

    cout << "Enter two numbers: ";
    cin >> number1 >> number2;

    cout << "The greater number is: " << findGreater(number1, number2) << endl;

    return 0;
}