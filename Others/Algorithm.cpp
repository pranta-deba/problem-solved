#include<iostream>

using namespace std;

int main()
{
    
    int N;
    cin >> N;
    int factorial = 1;
    for (int i = 1; i <= N; ++i) {
        factorial = (factorial * i) % 10000;
    }
    cout << factorial << endl;

    return 0;
}