#include <iostream>
#include <vector>

using namespace std;

const int MAX_TEMP = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    if (!(cin >> n >> k >> q)) return 0;

    vector<int> diff(MAX_TEMP + 2, 0);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> pref(MAX_TEMP + 2, 0);
    int current_recipes = 0;
    for (int i = 1; i <= MAX_TEMP; ++i) {
        current_recipes += diff[i];
        pref[i] = pref[i - 1] + (current_recipes >= k ? 1 : 0);
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }

    return 0;
}
