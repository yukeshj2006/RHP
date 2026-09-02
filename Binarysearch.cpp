#include <bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int>& arr, int target) {
   int low = 0, high = arr.size() - 1, result = -1;
   while (low <= high) {
       int mid = low + (high - low) / 2;
       if (arr[mid] == target) {
           result = mid; // store index
           high = mid - 1; // move left to find earlier occurrence
       }
       else if (arr[mid] > target)
           high = mid - 1;
       else
           low = mid + 1;
   }
   return result;
}
int main() {
   vector<int> arr = {1, 2, 4, 4, 4, 5, 6};
   int target = 4;
   int idx = firstOccurrence(arr, target);
   if (idx != -1)
       cout << "First occurrence at index: " << idx << endl;
   else
       cout << "Not found" << endl;
}
