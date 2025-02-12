#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> arr, int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++) // 1*n
    {
        for (int j = 0; j < n - i - 1; j++) // n*n
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}