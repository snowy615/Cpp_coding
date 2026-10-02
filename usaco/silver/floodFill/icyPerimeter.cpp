#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int n;
    cin >> n;
    vector<string> g(n);
    for (auto &row: g) cin >> row;

    auto isIce = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n && g[r][c] == '#';
    };

    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    int bestA = 0, bestP = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (g[r][c] != '#' || seen[r][c]) continue;
            int a = 0, p = 0;
            queue<pair<int, int>> q;
            q.push({r,c});
            seen[r][c] = true;
            while (!q.empty()) {
                auto [x,y] = q.front();
                q.pop();
                a++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dr[d], ny = y + dc[d];
                    if (!isIce(nx, ny)) p++;
                    else if (!seen[nx][ny]) {
                        seen[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            if (a > bestA || (a == bestA && p < bestP)) {
                bestA = a;
                bestP = p;
            }
        }
    }
    cout << bestA << " " << bestP;
    return 0;
}