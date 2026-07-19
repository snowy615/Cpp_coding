//new x = row+col, new y = row-col+N, rotate 45 degrees
//diamond becomes square

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int max_coord = 2*n+1;

    vector<vector<ll>> t(max_coord+1, vector<ll>(max_coord+1, 0));

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            ll grass;
            cin >> grass;
            int x = r+c;
            int y = r-c+n;
            t[x][y] = grass;
        }
    }

    vector<vector<ll>> p(max_coord+1, vector<ll>(max_coord+1, 0));
    for (int i = 1; i <= max_coord; i++) {
        for (int j = 1; j <= max_coord; j++) {
            p[i][j] = t[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }

    ll max_grass = 0;
    for (int r=1; r <= n; r++) {
        for (int c=1; c <= n; c++) {
            int x = r+c;
            int y = r-c+n;
            int x1 = max(1, x-k);
            int y1 = max(1, y-k);
            int x2 = min(max_coord, x+k);
            int y2 = min(max_coord, y+k);

            ll cur_grass = p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
            max_grass = max(cur_grass, max_grass);
        }
    }
    cout << max_grass;
    return 0;
}