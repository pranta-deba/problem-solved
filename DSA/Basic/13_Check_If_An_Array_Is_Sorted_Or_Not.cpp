#include <bits/stdc++.h>
using namespace std;

// Function that returns true if vector is
// sorted in non-decreasing order.
bool isSorted(const vector<int> &arr)
{
    // For an array to be sorted, every
    // element must be greater than the
    // previous element
    for (int i = 1; i < arr.size(); i++)
        if (arr[i - 1] > arr[i])
            return false;

    return true;
}

// Driver code
int main()
{
    vector<int> arr = {20, 23, 23, 45, 78, 88};
    cout << (isSorted(arr) ? "Yes\n" : "No\n");
    return 0;
}