#include <bits/stdc++.h>
using namespace std;
const int M = 1000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> diff(M+2, vector<int>(M+2, 0));
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        diff[x1][y1]++;
        diff[x1][y2]--;
        diff[x2][y1]--;
        diff[x2][y2]++;
    }

    vector<vector<int>> coats(M+1, vector<int>(M+1, 0));
    int valid_area = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int val = diff[i][j];
            if (i > 0) val += coats[i-1][j];
            if (j > 0) val += coats[i][j-1];
            if (i > 0 && j > 0) val -= coats[i-1][j-1];
            coats[i][j] = val;

            if (val == k) {
                valid_area ++;
            }
        }
    }

    cout << valid_area;
    return 0;
}