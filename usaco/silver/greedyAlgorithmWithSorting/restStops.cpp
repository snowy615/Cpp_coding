#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll L, N, rF, rB;
    cin >> L >> N >> rF >> rB;

    vector<pair<ll, ll>> stops(N);
    for (int i = 0; i < N; i++) {
        cin >> stops[i].first >> stops[i].second;
    }

    vector<bool> is_max(N, false);
    ll cur_max_tastiness = 0;
    for (int i = N-1; i >= 0; i--) {
        if (stops[i].second > cur_max_tastiness) {
            is_max[i] = true;
            cur_max_tastiness = stops[i].second;
        }
    }

    ll total_tastiness = 0;
    ll last_pos = 0;

    for (int i = 0; i < N; i++) {
        if (is_max[i]) {
            ll dist = stops[i].first - last_pos;
            ll wait_time = dist * (rF-rB);
            total_tastiness += wait_time * stops[i].second;
            last_pos = stops[i].first;
        }
    }

    cout << total_tastiness;
    return 0;
}