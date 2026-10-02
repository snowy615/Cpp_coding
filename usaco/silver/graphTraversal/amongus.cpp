#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//h[x] = 1 if human, 0 if parasite
//type 1 h[i] != h[j]
//type 2 h[i] == h[j]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<vector<pair<int, int>>> adj(n+1);
        for (int k = 0; k < q; k++) {
            int t, i, j;
            cin >> t >> i >> j;
            int diff = (t == 1); // accuse = dif, vouch = same
            adj[i].push_back({j, diff});
            adj[j].push_back({i, diff});
        }

        vector<int> side(n+1, -1);
        ll ans = 0;
        bool ok = true;
        for (int s = 1; s <= n && ok; s++) {
            if (side[s] != -1) continue;
            int cnt[2] = {0,0};
            queue<int> bfs;
            bfs.push(s);
            side[s] = 0;
            while (!bfs.empty() && ok) {
                int u = bfs.front();
                bfs.pop();
                cnt[side[u]]++;
                for (auto [v, diff]: adj[u]) {
                    int want = side[u] ^ diff;
                    if (side[v] == -1) {
                        side[v] = want;
                        bfs.push(v);
                    } else if (side[v] != want) ok = false; // contradiction
                }
            }
            ans += max(cnt[0], cnt[1]);

        }
        cout << (ok ? ans: -1) << "\n";
    }
    return 0;

}