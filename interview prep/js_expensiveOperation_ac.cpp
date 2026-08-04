#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//time of slowest thread (consecutive) + log2 N to glue together, N threads, spt = suboperations_processing_times
int get_processing_time(const vector<int>& spt, int N) {
    if (spt.empty()) return 0;
    int n = spt.size();

    ll left = 0;
    ll right = 0;
    for (int i = 0; i < n; i++) {
        left = max(left, (ll)spt[i]);
        right += spt[i] + 1;
    }

    ll ans = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        int cur_n_cnt = 1;
        ll cur_cnt = spt[0];
        bool possible = true;

        for (int i = 1; i < n; i++) {
            if (spt[i] > mid) {
                possible = false;
                break;
            }
            if (cur_cnt + spt[i] + 1 <= mid) {
                cur_cnt += spt[i] + 1;
            }else {
                cur_n_cnt ++;
                cur_cnt = spt[i];
            }
        }

        if (!possible || cur_n_cnt > N) {
            left = mid + 1;
        }else {
            ans = mid;
            right = mid - 1;
        }
    }

    int final_chunks = 1;
    ll final_cnt = spt[0];
    for (int i = 1; i < n; i++) {
        if (final_cnt + spt[i] + 1 <= ans) final_cnt += spt[i] + 1;
        else {
            final_chunks++;
            final_cnt = spt[i];
        }
    }

    int outer_joins = ceil(log2(final_chunks));

    return ans + outer_joins;
}
