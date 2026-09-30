#include <bits/stdc++.h>
using namespace std;

//graph of all edges i->j where cow i likes gift j at least as much as her own gift i. If cycle, then gift can reach her. BFS

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> pref(n+1, vector<int>(n+1));
    vector<vector<int>> adj(n+1);

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            cin >> pref[i][k];
        }
        for (int k = 1; k <= n; k++) {
            adj[i].push_back(pref[i][k]);
            if (pref[i][k] == i) break;
        }
    }

    vector<vector<char>> reach(n+1, vector<char>(n+1, 0));
    for (int s = 1; s <= n; s++) {
        vector<int> st = {s};
        reach[s][s] = 1;
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            for (int v: adj[u]) {
                if (!reach[s][v]) {
                    reach[s][v] = 1;
                    st.push_back(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            int g = pref[i][k];
            if (reach[g][i]) {
                cout << g << "\n";
                break;
            }

        }
    }
    return 0;
}