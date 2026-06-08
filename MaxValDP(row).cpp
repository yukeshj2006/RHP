#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int a[100][100];
    int dp[100][100];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < cols; j++) {
        dp[0][j] = a[0][j];
    }

    for(int i = 1; i < rows; i++) {
        int max1 = -1000000000;
        int max2 = -1000000000;
        int maxCol = -1;

        for(int j = 0; j < cols; j++) {
            if(dp[i - 1][j] > max1) {
                max2 = max1;
                max1 = dp[i - 1][j];
                maxCol = j;
            }
            else if(dp[i - 1][j] > max2) {
                max2 = dp[i - 1][j];
            }
        }

        for(int j = 0; j < cols; j++) {
            if(j == maxCol)
                dp[i][j] = a[i][j] + max2;
            else
                dp[i][j] = a[i][j] + max1;
        }
    }

    int ans = dp[rows - 1][0];

    for(int j = 1; j < cols; j++) {
        if(dp[rows - 1][j] > ans) {
            ans = dp[rows - 1][j];
        }
    }

    cout << ans;

    return 0;
}