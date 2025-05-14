// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if the word is found
bool isWordPresent(string sentence, string word)
{
    // To break the sentence in words
    stringstream s(sentence);

    // To temporarily store each individual word
    string temp;

    while (s >> temp)
    {

        // Comparing the current word
        // with the word to be searched
        if (temp.compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Driver code
int main()
{
    string s = "Geeks for Geeks";
    string word = "Geeks";

    if (isWordPresent(s, word))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}