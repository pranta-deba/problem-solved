#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int startIdx = 0;
    int endIdx = arr.size() - 1;
    int loc = 0;

    while (startIdx <= endIdx)
    {
        int mid = (startIdx + endIdx) / 2;
        loc++;

        if (target > arr[mid])
        {
            startIdx = mid + 1;
        }
        else if (target < arr[mid])
        {
            endIdx = mid - 1;
        }
        else
        {
            cout << "No of comparison : " << loc << endl;
            return mid;
            break;
        }
    }
    return -1;
};

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

    int target;
    cout << "Enter a Find Value: ";
    cin >> target;

    int result = binarySearch(arr, target);
    if (result >= 0)
    {
        cout << "The value find in : " << result << " Index" << endl;
    }
    else
    {
        cout << "The value NOT FOUND!" << endl;
    }
}
