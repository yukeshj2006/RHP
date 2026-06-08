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

    for(int i = 0; i < rows; i++) {
        dp[i][0] = a[i][0];
    }

    for(int j = 1; j < cols; j++) {
        int max1 = -1000000000;
        int max2 = -1000000000;
        int maxRow = -1;

        for(int i = 0; i < rows; i++) {
            if(dp[i][j - 1] > max1) {
                max2 = max1;
                max1 = dp[i][j - 1];
                maxRow = i;
            }
            else if(dp[i][j - 1] > max2) {
                max2 = dp[i][j - 1];
            }
        }

        for(int i = 0; i < rows; i++) {
            if(i == maxRow)
                dp[i][j] = a[i][j] + max2;
            else
                dp[i][j] = a[i][j] + max1;
        }
    }

    int ans = dp[0][cols - 1];

    for(int i = 1; i < rows; i++) {
        if(dp[i][cols - 1] > ans)
            ans = dp[i][cols - 1];
    }

    cout << ans;

    return 0;
}