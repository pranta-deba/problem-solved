#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> arr, int n) // O(n^2)
{
   
}
void printArray(vector<int> arr, int n)
{
    cout << "Sorted Array: ";
    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
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
    printArray(arr, n);

    return 0;
}