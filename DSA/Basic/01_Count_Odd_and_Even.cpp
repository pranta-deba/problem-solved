#include <iostream>
#include <vector>
using namespace std;

pair<int, int> countOddEven(vector<int> &arr)
{
    int countOdd = 0, countEven = 0;
    for (int i = 0; i < arr.size(); i++)
    {

        // checking if the element is even
        if (arr[i] % 2 == 0)
        {
            countEven++;
        }

        // if not even, it must be odd
        else
        {
            countOdd++;
        }
    }
    return {countOdd, countEven};
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    pair<int, int> ans = countOddEven(arr);
    cout << ans.first << " " << ans.second;
    return 0;
}