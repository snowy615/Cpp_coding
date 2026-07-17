#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    vector<int> min_r(10, n), max_r(10, -1), min_c(10, n), max_c(10, -1);
    set<int> pcolors;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            int color = row[j] - '0';
            board[i][j] = color;
            if (color != 0) {
                pcolors.insert(color);
                min_r[color] = min(min_r[color], i);
                max_r[color] = max(max_r[color], i);
                min_c[color] = min(min_c[color], j);
                max_c[color] = max(max_c[color], j);

            }
        }
    }

    set<int> not_first;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur_color = board[i][j];
            if (cur_color == 0) continue;
            for (int color = 1; color <= 9; color++) {
                if (color == cur_color || pcolors.find(color) == pcolors.end()) continue;
                if (i >= min_r[color] && i <= max_r[color] && j >= min_c[color] && j <= max_c[color]) not_first.insert(cur_color);
            }
        }
    }

    int cnt = pcolors.size()-not_first.size();
    cout << cnt << endl;
    return 0;

}