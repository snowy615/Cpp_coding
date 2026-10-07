#include <bits/stdc++.h>
using namespace std;

int n, r1, c1, r2, c2;
char g[20][20];
bool vis[20][20];

void dfs(int r, int c, char ch) { //flood fill
    if (r < r1 || r > r2 || c < c1 || c > c2 || vis[r][c] || g[r][c] != ch) return;
    vis[r][c] = true;
    dfs(r+1, c, ch);
    dfs(r, c+1, ch);
    dfs(r-1, c, ch);
    dfs(r, c-1, ch);
}

bool valid() {
    memset(vis, 0, sizeof vis);
    int cnt[26] = {};
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (!vis[i][j]) {
                cnt[g[i][j] - 'A']++;
                dfs(i, j, g[i][j]);
            }
        }
    }
    vector<int> v;
    for (int x: cnt) {
        if (x) v.push_back(x);

    }
    return v.size() == 2 && min(v[0], v[1]) == 1 && max(v[0], v[1]) >= 2;
}

int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<array<int, 4>> good;
    for (r1 = 0; r1 < n; r1++) {
        for (c1 = 0; c1 < n; c1++) {
            for (r2 = r1; r2 < n; r2++) {
                for (c2 = c1; c2 < n; c2++) {
                    if (valid()) good.push_back({r1, c1, r2, c2});
                }
            }
        }
    }

    int ans = 0;
    for (auto &a: good) {
        bool inside = false;
        for (auto &b: good) {
            if (a != b && b[0] <= a[0] && b[1] <= a[1] && b[2] >= a[2] && b[3] >= a[3]) inside = true;
        }
        ans += !inside;
    }

    cout << ans << "\n";
}
