#include <bits/stdc++.h>
using namespace std;

int lowest_energy_seam(const vector<vector<int>>& energy_matrix) {
    int l = energy_matrix[0].size();
    int w = enery_matrix.size();
    vector<vector<int>> dp(w, vector<int>(l, 0));
    for (int i = 0; i < l; i++) {
        dp[0][i] = energy_matrix[0][i];
    }
    int ans = 0;
    for (int row = 1; row < l; row++) {
        for (int col = 0; col < w; col++) {
            dp[row][col] = dp[row-1][col] + energy_matrix[row][col];
            if (col >= 1) dp[row][col] = min(dp[row][col], dp[row-1][col-1]+energy_matrix[row][col]);
            if (col < w-1) dp[row][col] = min(dp[row][col], dp[row-1][col+1] + energy_matrix[row][col]);
            if (row == l-1) ans = max(ans, dp[row][col]);
        }

    }
    return ans;
}
