#include <bits/stdc++.h>
using namespace std;
//find room, add count, flood fill

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &row: g) cin >> row;

    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int rooms = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (g[r][c] != '.') continue; // wall or visited
            rooms ++;
            g[r][c] = '#';
            queue<pair<int, int>> q;
            q.push({r, c});
            while (!q.empty()) {
                auto [x,y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dr[d];
                    int ny = y + dc[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '.') {
                        g[nx][ny] = '#';
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << rooms;
    return 0;

}