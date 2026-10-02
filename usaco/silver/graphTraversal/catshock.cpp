#include <bits/stdc++.h>
using namespace std;
//checkerboard alternate, delete farthest node when safe.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for (int k = 0; k < n-1; k++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //BFS
        vector<int> dep(n+1, -1), order;
        dep[n] = 0;
        order.push_back(n);
        for (int i = 0; i< (int) order.size(); i++) {
            for (int v: adj[order[i]]) {
                if (dep[v] == -1) {
                    dep[v] = dep[order[i]] + 1;
                    order.push_back(v);
                }
            }
        }

        vector<string> ops;
        int cat = dep[1] % 2;
        for (int i = n - 1; i >= 1; i--) {
            int u = order[i];
            if (cat == dep[u] % 2) {
                ops.push_back("1");
                cat ^= 1;
            }
            ops.push_back("2 " + to_string(u));
            ops.push_back("1");
            cat ^= 1;
        }
        cout << ops.size() << "\n";
        for (auto &s: ops) cout << s << "\n";
    }
    return 0;
}