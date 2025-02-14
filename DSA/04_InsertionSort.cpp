#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr, int n)
{
    cout << "Sorted Array: ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }

    printArr(arr, n);
}

int main()
{
    int n;
    cout << "Enter a size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter a elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    return 0;
}