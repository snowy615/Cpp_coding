#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<ll> x(n), y(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }

    //adj[i] = cows that cow i can transmit directly
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            if (dx * dx + dy * dy <= p[i] * p[i]) adj[i].push_back(j);
        }
    }

    int best = 0;
    for (int start = 0; start < n; start++) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int count = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count ++;
                    q.push(v);
                }
            }
        }
        best = max(best, count);
    }
    cout << best;
    return 0;
}