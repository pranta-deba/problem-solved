#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid); // left half
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    return 0;
}