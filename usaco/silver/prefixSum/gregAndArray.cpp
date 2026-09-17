#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    //1-indexed array
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    //operations
    vector<int> l(m+1), r(m+1);
    vector<ll> d(m+1);
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> d[i];

    vector<ll> op_diff(m+2, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        op_diff[x]++;
        op_diff[y+1]--;
    }
    vector<ll>op_cnt(m+1, 0);
    ll cur_ops = 0;
    for (int i = 1; i <= m; i++) {
        cur_ops += op_diff[i];
        op_cnt[i] = cur_ops;
    }

    vector<ll> arr_diff(n+2, 0);
    for (int i = 1; i <= m; i++) {
        ll times = op_cnt[i];
        if (times > 0) {
            ll total_add = times*d[i];
            arr_diff[l[i]] += total_add;
            arr_diff[r[i]+1] -= total_add;
        }
    }

    ll cur_add = 0;
    for (int i = 1; i <= n; i++) {
        cur_add += arr_diff[i];
        cout << a[i] + cur_add << " ";
    }
    return 0;
}