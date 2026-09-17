#include <bits/stdc++.h>
using namespace std;

//forest

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> prev_v(n+1, vector<int>(m+1, 0));
    vector<vector<int>> prev_eh(n+1, vector<int>(m+1, 0));
    vector<vector<int>> prev_ev(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int v = (s[i-1][j-1] == '1') ? 1:0;
            int eh = (j < m && s[i-1][j-1] == '1' && s[i-1][j] == '1')?1:0;
            int ev = (i < n && s[i-1][j-1] == '1' && s[i][j-1] == '1') ? 1:0;
            prev_v[i][j] = v+prev_v[i-1][j] + prev_v[i][j-1] - prev_v[i-1][j-1];
            prev_eh[i][j] = eh + prev_eh[i-1][j] + prev_eh[i][j-1] - prev_eh[i-1][j-1];
            prev_ev[i][j] = ev + prev_ev[i-1][j] + prev_ev[i][j-1] - prev_ev[i-1][j-1];

        }
    }

    auto get_sum = [&](const vector<vector<int>>& prev, int r1, int c1, int r2, int c2) -> int {
        if (r1 > r2 || c1 > c2) return 0;
        return prev[r2][c2] - prev[r1-1][c2] - prev[r2][c1-1] + prev[r1-1][c1-1];
    };

    for (int k = 0; k < q; k++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int v = get_sum(prev_v, r1, c1, r2, c2);
        int eh = get_sum(prev_eh, r1, c1, r2, c2-1);
        int ev = get_sum(prev_ev, r1, c1, r2-1, c2);
        int components = v-eh-ev;
        cout << components << "\n";
    }
    return 0;
}