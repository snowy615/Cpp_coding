#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//prefix sum + bfs

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    //adj[u] = list of {v, w} so P[v] = P[u]+w
    vector<vector<pair<int, ll>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int l, r;
        ll s;
        cin >> l >> r >> s;
        adj[l-1].push_back({r, s});
        adj[r].push_back({l-1, -s});
    }

    vector<ll> P(n+1, 0);
    vector<bool> assigned(n+1, false);

    for (int start = 0; start <= n; start++) {
        if (assigned[start]) continue;

        P[start] = 0;
        assigned[start] = true;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v,w]: adj[u]) {
                if (!assigned[v]) {
                    P[v] = P[u] + w;
                    assigned[v] = true;
                    q.push(v);
                }else if (P[v] != P[u] + w) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << P[i] - P[i-1] << " ";
    }
    return 0;

}