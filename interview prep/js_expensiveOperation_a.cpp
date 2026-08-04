#include <bits/stdc++.h>
using namespace std;
using ll = long long

//time of slowest thread (consecutive) + 1, N threads, spt = suboperations_processing_times
int get_processing_time(const vector<int>& spt, int N) {
    int n = spt.size();
    vector<ll> ps(n, 0);
    for (int i = 0; i < n; i++) {
        ps[i] = ps[i-1]+spt[i];
    }
    //binary search of min time
    int left = 0, right = ps[n-1]+n, ans = 0;
    while (left <= right) {
        int mid = left + (right-left)/2;
        cur_n_cnt = 1;
        cur_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cur_cnt + spt[i] > mid) {
                cur_n_cnt ++;
                cur_cnt = spt[i];
            }else {
                cur_cnt += spt[i];
            }
        }
        if (cur_n_cnt > N) right = mid-1;
        else {
            left = mid+1;
            ans = mid;
        }
    }
    return ans;
}
