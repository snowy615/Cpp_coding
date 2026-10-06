#include <bits/stdc++.h>
using namespace std;
//binary search + flood fill

int M, N;
vector<vector<int>> h; //height
vector<vector<int>>isWay; //1 if waypoint
int tw = 0; // total way
int startr = -1, startc = -1;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool works(int D) {
    vector<vector<bool>> seen(M, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({startr, startc});
    seen[startr][startc] = true;
    int reached = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (isWay[r][c]) reached ++;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N || seen[nr][nc] || abs(h[nr][nc] - h[r][c])>D) continue;
            seen[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return reached == tw;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> M >> N;
    h.assign(M, vector<int>(N));
    isWay.assign(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> h[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> isWay[i][j];
            if (isWay[i][j]) {
                tw ++;
                startr = i;
                startc = j;
            }
        }
    }

    if (tw <= 1) {
        cout << 0;
        return 0;
    }

    int low = 0, high = 1e9;
    while (low < high) {
        int m = low + (high-low)/2;
        if (works(m)) high = m;
        else low = m+1;
    }
    cout << low;
    return 0;
    
}