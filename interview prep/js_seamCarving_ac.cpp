#include <bits/stdc++.h>
using namespace std;

int lowest_energy_seam(const vector<vector<int>>& energy_matrix) {
    if (energy_matrix.empty() || energy_matrix[0].empty()) return 0;

    int rows = energy_matrix.size();
    int cols = energy_matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int c = 0; c < cols; c++) {
        dp[0][c] = energy_matrix[0][c];
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            int min_prev = dp[r-1][c];
            if (c > 0) min_prev = min(min_prev, dp[r-1][c-1]);
            if (c < cols-1) min_prev = min(min_prev, dp[r-1][c+1]);

            dp[r][c] = energy_matrix[r][c] + min_prev;
        }
    }

    int ans = INT_MAX;
    for (int c = 0; c < cols; c++) {
        ans = min(ans, dp[rows-1][c]);
    }

    return ans;
}
