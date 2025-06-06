// CPP code to find max element in a matrix
#include <bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

// Function to find max element
// mat[][] : 2D array to find max element
int findMax(int mat[N][M])
{

    // Initializing max element as INT_MIN
    int maxElement = INT_MIN;

    // checking each element of matrix
    // if it is greater than maxElement,
    // update maxElement
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] > maxElement)
            {
                maxElement = mat[i][j];
            }
        }
    }

    // finally return maxElement
    return maxElement;
}

// Driver code
int main()
{

    // matrix
    int mat[N][M] = {{1, 2, 3, 4},
                     {25, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    cout << findMax(mat) << endl;

    return 0;
}