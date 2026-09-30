#include <bits/stdc++.h>
using namespace std;



int n, m;

vector<bool> bfs(const vector<vector<int>>& g) {
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return visited;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> adj(n+1), radj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a); //reverse
    }

    //BFS on adj from 1: can 1 reach everyone?
    vector<bool> fwd = bfs(adj);
    for (int v = 1; v <= n; v++) {
        if (!fwd[v]) {
            cout << "NO\n" << 1 << " " << v << "\n";
            return 0;
        }
    }

    //BFS on radj from 1: can everyone reach 1?
    vector<bool> back = bfs(radj);
    for (int v = 1; v <= n; v++) {
        if (!back[v]) {
            cout << "NO\n" << v << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;

}