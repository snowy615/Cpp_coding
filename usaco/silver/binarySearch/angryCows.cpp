#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(ll R, const vector<int>&x, int K) {
    int cows_used = 0;
    int n = x.size();
    int i = 0;
    while (i < n) {
        cows_used ++;
        ll limit = (ll) x[i] + 2LL * R;
        while (i < n && x[i] <= limit) i++;
    }
    return cows_used <= K;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    ll left = 0;
    ll right = 1e9;
    ll ans = right;

    while (left < right) {
        ll mid = left + (right-left)/2;
        if (isValid(mid, x, k)) {
            ans = mid;
            right = mid;
        }else {
            left = mid+1;
        }
    }
    cout << ans;
    return 0;

    
}