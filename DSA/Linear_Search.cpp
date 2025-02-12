//  Linear Search
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int result = linearSearch(arr, size, target);

    if (result >= 0)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found in array" << endl;
    }
}