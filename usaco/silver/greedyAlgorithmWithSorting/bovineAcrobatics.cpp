#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll M, K;
    cin >> N >> M >> K;

    vector<pair<ll, ll>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    map<ll, ll> towers;

    const ll INF = 2e18;
    towers[-INF] = M;

    ll total_cows = 0;

    for (int i = 0; i < N; i++) {
        ll W = cows[i].first;
        ll C = cows[i].second;
        ll count_used = 0;

        while (count_used < C) {
            auto it = towers.upper_bound(W-K);
            if (it == towers.begin()) break;
            it --;

            ll take = min(C - count_used, it -> second);
            count_used += take;
            it->second -= take;

            if (it -> second == 0) towers.erase(it);
        }
        if (count_used > 0) {
            towers[W] += count_used;
            total_cows += count_used;
        }
    }
    cout << total_cows;
    return 0;

}