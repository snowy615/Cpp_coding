#include <bits/stdc++.h>
using namespace std;
const int M = 200;

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
    vector<vector<int>> benefit(M, vector<int>(M, 0));
    int initial_k_area = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int val = diff[i][j];
            if (i > 0) val += coats[i-1][j];
            if (j > 0) val += coats[i][j-1];
            if (i > 0 && j > 0) val -= coats[i-1][j-1];
            coats[i][j] = val;

            if (val == k) {
                initial_k_area ++;
                benefit[i][j] = -1;
            }else if (val == k - 1) {
                benefit[i][j] = 1;
            }else {
                benefit[i][j] = 0;
            }
        }
    }


    vector<int> up(M+1, 0), down(M+1, 0), left(M+1, 0), right(M+1, 0);

    //2D Kadane up/down for horizontal split
    //r1, r2 top,bottom edge of rectangle
    for (int r1 = 0; r1 < M; r1++) {
        vector<int> col_sum(M, 0);
        for (int r2 = r1; r2 < M; r2++) {
            int cur_sum = 0, max_val = 0;
            //1D Kadane's algo
            for (int c = 0; c < M; c++) {
                col_sum[c] += benefit[r2][c];
                cur_sum = max(0, cur_sum + col_sum[c]);
                max_val = max(max_val, cur_sum);
            }
            up[r2] = max(up[r2], max_val);
            down[r1] = max(down[r1], max_val);
        }
    }
    //left/right for vertical split
    for (int c1 = 0; c1 < M; c1++) {
        vector<int> row_sum(M, 0);
        for (int c2 = c1; c2 < M; c2++) {
            int cur_sum = 0, max_val = 0;
            for (int r = 0; r < M; r++) {
                row_sum[r] += benefit[r][c2];
                cur_sum = max(0, cur_sum+row_sum[r]);
                max_val = max(max_val, cur_sum);
            }
            left[c2] = max(left[c2], max_val);
            right[c1] = max(right[c1], max_val);
        }
    }

    for (int i = 1; i < M; i++) {
        up[i] = max(up[i], up[i-1]);
        left[i] = max(left[i], left[i-1]);
    }
    for (int i = M-2; i >= 0; i--) {
        down[i] = max(down[i], down[i+1]);
        right[i] = max(right[i], right[i+1]);
    }

    int max_extra_area = 0;
    for (int i = 0; i < M - 1; i++) {
        max_extra_area = max(max_extra_area, up[i]+down[i+1]);
        max_extra_area = max(max_extra_area, left[i] + right[i+1]);
    }

    cout << initial_k_area + max_extra_area;
    return 0;


}