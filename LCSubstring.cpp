#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getLCSubstring(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0; 

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]); 
            } else {
                dp[i][j] = 0; 
            }
        }
    }
    return maxLength;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << "Longest Common Substring Length: " << getLCSubstring(s1, s2) << endl;
    return 0;
}