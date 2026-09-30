#include <bits/stdc++.h>
using namespace std;

//tree cow always eat, first extra cow eats in each component, all others starve. First let extra cow eat, then the tree cows
//dsu with bfs

vector<int> par;
int find(int x) {
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> f(n+1), s(n+1);
    par.resize(m+1);
    iota(par.begin(), par.end(), 0);
    vector<vector<pair<int, int>>> adj(m+1); // adj[cereal] = {other cereal, cow}
    vector<int> extra;

    for (int i = 1; i <= n; i++) {
        cin >> f[i] >> s[i];
        int a = find(f[i]);
        int b = find(s[i]);
        if (a != b) { //tree
            par[a] = b;
            adj[f[i]].push_back({s[i], i});
            adj[s[i]].push_back({f[i], i});
        } else extra.push_back(i); //extra
    }

    vector<int> special(m+1, 0), hungry;
    for (int c: extra) {
        int r = find(f[c]);
        if (!special[r]) special[r] = c;
        else hungry.push_back(c);
    }

    vector<int> order;
    vector<char> vis(m+1, 0);
    for (int x = 1; x <= m; x++) {
        if (!vis[x]) {
            int r = find(x);
            int root = x;
            if (special[r]) {
                order.push_back(special[r]);
                root = f[special[r]];
            }
            queue<int> q;
            q.push(root);
            vis[root] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto [v, cow]: adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        order.push_back(cow);
                        q.push(v);
                    }
                }
            }

        }
    }

    for (int c: hungry) order.push_back(c);
    cout << hungry.size() << "\n";
    for (int c: order) cout << c << "\n";
    return 0;

}