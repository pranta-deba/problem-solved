// #include <iostream>
// using namespace std;
// int main() {
//     int N;
//     cin >> N;
//     if (N >= 10) {
//         cout << "0000" << endl;
//         return 0;
//     }
//     int factorial = 1;
//     for (int i = 1; i <= N; ++i) {
//         factorial = (factorial * i) % 10000;
//     }
//     cout << factorial << endl;
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     string N;
//     cin >> N;
//     vector<int> frequency(10, 0);
//     for (char digit : N)
//     {
//         frequency[digit - '0']++;
//     }
//     int maxFreq = 0;
//     int resultDigit = 0;

//     for (int i = 0; i < 10; i++)
//     {
//         if (frequency[i] > maxFreq)
//         {
//             maxFreq = frequency[i];
//             resultDigit = i;
//         }
//         else if (frequency[i] == maxFreq && i < resultDigit)
//         {
//             resultDigit = i;
//         }
//     }
//     cout << resultDigit << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// #include <climits>
// using namespace std;
// int calculate_cost(const string &s)
// {
//     int cost = 0;
//     for (char c : s)
//     {
//         cost += (c - 'a' + 1);
//     }
//     return cost;
// }
// int main()
// {
//     int N;
//     cin >> N;
//     long long total_cost = 0;
//     while (N--)
//     {
//         string players;
//         cin >> players;
//         int len = players.length();
//         int min_cost = INT_MAX;
//         string min_substring;
//         string doubled_players = players + players;
//         for (int i = 0; i <= len; ++i)
//         {
//             string sub = doubled_players.substr(i, 15);
//             int cost = calculate_cost(sub);
//             if (cost < min_cost)
//             {
//                 min_cost = cost;
//                 min_substring = sub;
//             }
//         }
//         total_cost += min_cost;
//     }
//     cout << total_cost << endl;
//     return 0;
// }



// #include <iostream>
// #include <set>
// using namespace std;
// int main() {
//     int K, X;
//     cin >> K >> X;
//     set<int> result;
//     for (int i = -K + 1; i <= K - 1; ++i) {
//         result.insert(X + i);
//     }
//     for (auto coord : result) {
//         cout << coord << " ";
//     }
//     cout << endl;
//     return 0;
// }




#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    string result = "";
    for (int i = 0; i < N; ++i) {
        result += S[i];
        result += T[i];
    }
    cout << result << endl;
    
    return 0;
}
