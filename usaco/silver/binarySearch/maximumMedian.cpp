#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll low = 1, high = a[n/2]+k, ans = a[n/2];

    while (low <= high) {
        ll mid = low + (high-low)/2;
        ll ops = 0; // operation count

        for (int i = n/2; i < n; i++) {
            if (a[i] < mid) ops += mid - a[i];
            if (ops > k) break;
        }
        if (ops <= k) {
            ans = mid;
            low = mid+1;
        }else {
            high = mid-1;
        }
    }

    cout << ans;
    return 0;

}