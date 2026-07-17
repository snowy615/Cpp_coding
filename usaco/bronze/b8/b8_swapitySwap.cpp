#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> cows(n+1);
    iota(cows.begin(), cows.end(), 0); //fills 0, 1, 2...

    reverse(cows.begin()+a1, cows.begin()+a2+1);
    reverse(cows.begin()+b1, cows.begin()+b2+1);

    vector<int> next_pos(n+1);
    for (int i = 1; i <= n; i++) {
        next_pos[cows[i]] = i;
    }

    vector <int> ans(n+1);
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cycle.push_back(cur);
                cur = next_pos[cur];
            }
            int cycle_length = cycle.size();
            for (int j = 0; j < cycle_length; j++) {
                int final_pos = cycle[(j+k)%cycle_length];
                ans[final_pos] = cycle[j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}