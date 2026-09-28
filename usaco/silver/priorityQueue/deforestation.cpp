#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    vector<vector<pair<int, int>>> starts(n+1);

    for (int i = 0; i < k; i++) {
        int l, r, t;
        cin >> l >> r >> t;

        int u = lower_bound(x.begin(), x.end(), l) - x.begin() + 1;
        int v = upper_bound(x.begin(), x.end(), r) - x.begin();

        if (u <= v) starts[u].push_back({v,t});
    }

    //min pq {Mj, vj} Mj most restrictive constraint bound
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int C = 0; //cut trees
    for (int i = 1; i <= n; i++) {
        for (auto& constraint: starts[i]) {
            int v = constraint.first;
            int t = constraint.second;
            int M = (v-i+1) - t + C;
            pq.push({M, v});
        }

        while (!pq.empty() && pq.top().second < i) pq.pop();

        if (pq.empty()) {
            C++;
        } else {
            int min_M = pq.top().first;
            if (min_M > C) C++;
        }
    }

    cout << C << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}