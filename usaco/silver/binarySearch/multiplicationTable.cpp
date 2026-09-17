#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll low = 1;
    ll high = n * n;
    ll target = (n*n + 1) / 2;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high-low)/2;
        ll count = 0;

        for (ll i = 1; i <= n; i++) {
            count += min(n, mid/i);
        }

        if (count >= target) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}