#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;
    int max_color = n*n;
    vector<vector<int>> grid(n, vector<int>(n,0));


    vector<int> min_r(max_color+1, INF);
    vector<int> max_r(max_color+1, -INF);
    vector<int> min_c(max_color+1, INF);
    vector<int> max_c(max_color+1, -INF);

    vector<bool> visible(max_color+1, false);
    int visible_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            int x = grid[i][j];
            if (x > 0) {
                if (!visible[x]) {
                    visible[x] = true;
                    visible_cnt ++;
                }
                min_r[x] = min(min_r[x], i);
                max_r[x] = max(max_r[x], i);
                min_c[x] = min(min_c[x], j);
                max_c[x] = max(max_c[x], j);
            }
        }
    }

    if (visible_cnt == 0) {
        cout << 0;
        return 0;
    }else if (visible_cnt == 1) {
        if (n == 1) cout << 1;
        else cout << max_color-1;
        return 0;
    }

    vector<vector<int>> diff(n+2, vector<int>(n+2, 0)); //1-indexed
    for (int c = 1; c <= max_color; c++) {
        if (visible[c]) {
            int r1 = min_r[c], r2 = max_r[c];
            int c1 = min_c[c], c2 = max_c[c];

            diff[r1+1][c1+1]++;
            diff[r1+1][c2+2]--;
            diff[r2+2][c1+1]--;
            diff[r2+2][c2+2]++;
        }
    }

    vector<bool> fst(max_color+1, true); //can be first
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            diff[i][j] += diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            int x = grid[i-1][j-1];
            if (x > 0 && diff[i][j] > 1) fst[x] = false;
        }
    }

    int cnt = 0;
    for (int c = 1; c <= max_color; c++) {
        if (fst[c]) cnt ++;
    }

    cout << cnt;
    return 0;

}