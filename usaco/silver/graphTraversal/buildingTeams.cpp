#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1); //friends adj[i] = list of i's friends

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    vector<int> team(n+1, 0);
    for (int start = 1; start <= n; start++) {
        if (team[start] != 0) continue;
        team[start] = 1;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v: adj[u]) {
                if (team[v] == 0) {
                    team[v] = 3-team[u];
                    q.push(v);
                }else if (team[v] == team[u]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    return 0;
}