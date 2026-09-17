#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();

    vector<vector<bool>> is_p(n, vector<bool>(n, false));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) is_p[i][j] = true;
            else if (len == 2) is_p[i][j] = (s[i] == s[j]);
            else is_p[i][j] = (s[i] == s[j] && is_p[i+1][j-1]);

            if (len == 1) dp[i][j] = 1;
            else {
                int without_first = dp[i+1][j];
                int without_last = dp[i][j-1];
                int overlap = dp[i+1][j-1];
                int is_cur_p = is_p[i][j]?1:0;
                dp[i][j] = without_first+without_last-overlap+is_cur_p;

            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l-1][r-1] << "\n";
    }
    return 0;
}