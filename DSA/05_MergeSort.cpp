#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
}

void mergeSort(vector<int> &arr, int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, st, mid, end);
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    return 0;
}