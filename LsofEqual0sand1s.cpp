#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxLength(const vector<int>& nums) {
    unordered_map<int, int> sumMap;
    int maxLen = 0;
    int currentSum = 0;

    sumMap[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum += (nums[i] == 1) ? 1 : -1;

        if (sumMap.find(currentSum) != sumMap.end()) {
            maxLen = max(maxLen, i - sumMap[currentSum]);
        } else {
            sumMap[currentSum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cout << "Enter the size of the binary array: ";
    if (!(cin >> n) || n <= 0) {
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter the binary elements (0s and 1s): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "The maximum length of a subarray with equal 0s and 1s is: " 
         << findMaxLength(nums) << endl;

    return 0;
}