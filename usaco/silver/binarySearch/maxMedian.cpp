#include <bits/stdc++.h>
using namespace std;

//number >= x +1, number < x -1, if sum of +1, -1 > 0 subarray is at least x, use prefix sum

bool check(int x, const vector<int>& a, int k) {
    int n = a.size();
    vector<int> ps(n+1, 0);

    for (int i = 0; i < n; i++) {
        int val = (a[i] >= x) ? 1 : -1;
        ps[i+1] = ps[i] + val;
    }

    int min_ps = 1e9;

    for (int i = k; i <= n; i++) {
        min_ps = min(min_ps, ps[i-k]);
        if (ps[i] > min_ps) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 1;
    int right  = n;
    int ans = 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(mid, a, k)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;

        }
    }
    cout << ans;
    return 0;

}