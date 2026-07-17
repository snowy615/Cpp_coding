#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> grid (n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int flips = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (grid[i][j] == '1') {
                flips ++;
                for (int r = 0; r <= i; r++) {
                    for (int c = 0; c <= j; c++) {
                        if (grid[r][c] == '0') grid[r][c] = '1';
                        else grid[r][c] = '0';
                    }
                }
            }
        }
    }
    cout << flips;
    return 0;


}