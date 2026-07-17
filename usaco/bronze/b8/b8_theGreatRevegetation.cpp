#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> grass(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int type = 1; type <= 4; type++) {
            bool conflict = false;
            for (int neighbour:adj[i]) {
                if (grass[neighbour] == type) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                grass[i] = type;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << grass[i];
    }
    return 0;
}