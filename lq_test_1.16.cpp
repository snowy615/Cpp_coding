#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll k, n;                           // k = 喷头数, n = 管道长度
vector<pair<ll,ll>> num;           // {位置, 启动时间}
vector<pair<ll,ll>> x;             // 有效区间

bool check(ll t) {                 // ① 改成 ll
    x.clear();
    for (ll i = 0; i < k; ++i) {
        if (num[i].second <= t) {
            ll nl = max(1LL, num[i].first - (t - num[i].second));
            ll nr = min(n  , num[i].first + (t - num[i].second));
            x.push_back({nl, nr});
        }
    }
    if (x.empty()) return false;   // ③ 防越界
    sort(x.begin(), x.end());
    if (x[0].first > 1) return false;
    ll end = x[0].second;
    for (size_t i = 1; i < x.size(); ++i) {
        if (x[i].first > end+1) break;
        end = max(end, x[i].second);
    }
    return end >= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for (ll i = 0, v, t; i < k; ++i) {
        cin >> v >> t;
        num.push_back({v, t});
    }

    ll l = 0, r = 10000000000LL;   // ② 显式 LL
    while (l + 1 != r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}