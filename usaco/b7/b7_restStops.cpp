#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct stop {
    ll x;
    ll c;
};
int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    ll l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    vector<stop> stops(n);
    for (int i = 0; i < n; i++) {
        cin >> stops[i].x >> stops[i].c;
    }

    vector<bool> is_target(n, false);
    ll cur_max = 0;

    for (int i = n-1; i >= 0; i--) {
        if (stops[i].c > cur_max) {
            is_target[i] = true;
            cur_max = stops[i].c;
        }
    }
    ll tnt = 0;
    ll prev_x = 0;
    ll rate_dif = rf-rb;

    for (int i = 0; i < n; i++) {
        if (is_target[i]) {
            ll dx = stops[i].x - prev_x;
            ll rest_time = dx * rate_dif;
            tnt += rest_time * stops[i].c;
            prev_x = stops[i].x;
        }
    }
    cout << tnt;
    return 0;
}