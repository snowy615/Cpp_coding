#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        low = max(low, a[i]);
        high += a[i];
    }

    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        int subarrays = 1;
        ll cur = 0;

        for (ll x: a) {
            if (cur + x > mid) {
                subarrays++;
                cur = x;
            } else cur += x;
        }

        if (subarrays <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}