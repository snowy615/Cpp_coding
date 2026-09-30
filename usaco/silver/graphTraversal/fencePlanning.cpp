#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector <ll> x(n+1), y(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); //connections are mutual
    }

    vector<bool> visited(n+1, false);
    ll best = LLONG_MAX;
    for (int start = 1; start <= n; start++) {
        if (visited[start]) continue;
        ll minX = x[start], maxX = x[start];
        ll minY = y[start], maxY = y[start];
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            minX = min(minX, x[u]);
            maxX = max(maxX, x[u]);
            minY = min(minY, y[u]);
            maxY = max(maxY, y[u]);

            for (int v: adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        ll perimeter = 2 * ((maxX-minX) + (maxY-minY));
        best = min(best, perimeter);
    }
    cout << best;
    return 0;
}