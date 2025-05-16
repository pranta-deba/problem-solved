// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to display longest names
// contained in the array
vector<string> solve(string *arr, int N)
{
    // Edge Case
    if (N == 0)
        return {};

    // Initialize Max
    int Max = arr[0].size();

    // Create an array res
    vector<string> res;

    // Insert first element in res
    res.push_back(arr[0]);

    // Traverse the array
    for (int i = 1; i < N; i++)
    {

        // If string with greater length
        // is found
        if (arr[i].size() > Max)
        {
            Max = arr[i].size();
            res.clear();
            res.push_back(arr[i]);
        }

        // If string with current max length
        else if (arr[i].size() == Max)
        {
            res.push_back(arr[i]);
        }
    }

    // Return the final answer
    return res;
}

// Driver Code
int main()
{
    string arr[] = {"GeeksforGeeks", "FreeCodeCamp",
                    "StackOverFlow", "MyCodeSchool"};

    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    vector<string> v = solve(arr, N);

    // Printing the answer
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}