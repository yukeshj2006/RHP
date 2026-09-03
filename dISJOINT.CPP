#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector<int> &leader, int a) {
    if (leader[a] == a) {
        return leader[a];
    }
    return find(leader, leader[a]);
}

void join(vector<int>& ldr, int a, int b) {
    int ldrA = find(ldr, a);
    int ldrB = find(ldr, b);
    ldr[ldrB] = ldrA;
}

int main() {
    int N, M;

    cin >> N >> M;
    vector<int> leader(N + 1);
    for (int i = 1; i <= N; i++) {
        leader[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        join(leader, a, b);
    }

    set<int> st;
    for (int i = 1; i <= N; i++) {
        st.insert(find(leader, i));
    }

    cout << st.size();
}
