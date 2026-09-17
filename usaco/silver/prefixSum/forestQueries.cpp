#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> p(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            int is_tree = (row[j-1] == '*') ? 1:0;
            p[i][j] = is_tree + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int trees = p[y2][x2] - p[y1-1][x2] - p[y2][x1-1] + p[y1-1][x1-1];
        cout << trees << "\n";
    }
    return 0;
}