#include <bits/stdc++.h>
using namespace std;
//BFS, each component has 0 or 2 choices

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1); //adj[p] = {other pasture, S=0/D=1}
    for (int i = 0; i < m; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        int w = (t == 'D'); // 0 = same, 1 = dif
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> color(n+1, -1);
    int components = 0;
    for (int s = 1; s <= n; s++) {
        if (color[s] != -1) continue;
        components++;
        color[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w]: adj[u]) {
                int need = color[u] ^ w;
                if (color[v] == -1) {
                    color[v] = need;
                    q.push(v);
                }else if (color[v] != need) {
                    cout << 0;
                    return 0;
                }
            }
        }
    }

    cout << '1' << string(components, '0');
    return 0;



}