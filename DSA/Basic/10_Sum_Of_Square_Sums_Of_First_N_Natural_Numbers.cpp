#include<bits/stdc++.h>
using namespace std;

int Square_Diff(int n){
    int sumOfSquares = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sumOfSquares += pow(i, 2);
        sum += i;
    }

    int squareOfSum = pow(sum, 2);
    int absDifference = abs(sumOfSquares - squareOfSum);
    return absDifference;
}
int main() {
    int n = 10;
    cout << Square_Diff(n);
    return 0;
    return 0;
}