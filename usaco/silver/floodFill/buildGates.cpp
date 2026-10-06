#include <bits/stdc++.h>
using namespace std;

//flood fill, boundary create boxes to fill by double every coordinate, so leaves a cell between the cells to hold the fence segment

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int N;
    string s;
    cin >> N >> s;

    vector<pair<int, int>> fence;
    int x = 0;
    int y = 0;
    fence.push_back({x, y});
    for (char c: s) {
        int dx = 0, dy = 0;
        if (c == 'N') dy = 1;
        if (c == 'S') dy = -1;
        if (c == 'E') dx = 1;
        if (c == 'W') dx = -1;

        for (int k = 0; k < 2; k++) {
            x += dx, y += dy;
            fence.push_back({x, y}); //actual step = 2 steps in doubled coordinates
        }
    }

    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    for (auto [fx, fy]: fence) {
        minX = min(minX, fx);
        maxX = max(maxX, fx);
        minY = min(minY, fy);
        maxY = max(maxY, fy);
    }
    int W = maxX - minX + 3;
    int H = maxY - minY + 3;

    vector<vector<char>> blocked(W, vector<char>(H, 0));
    for (auto [fx, fy]: fence) {
        blocked[fx-minX+1][fy-minY+1] = 1;
    }

    vector<vector<char>> seen(W, vector<char>(H, 0));
    int dxs[4] = {1, -1, 0, 0};
    int dys[4] = {0, 0, 1, -1};
    int regions = 0;

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (blocked[i][j] || seen[i][j]) continue;
            regions++;
            queue<pair<int,int>> q;
            q.push({i, j});
            seen[i][j] = 1;

            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cx + dxs[k];
                    int ny = cy + dys[k];
                    if (nx < 0 || ny < 0 || nx >= W || ny >= H || blocked[nx][ny] || seen[nx][ny]) continue;
                    seen[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

        }
    }
    cout << regions - 1;
    return 0;

}
