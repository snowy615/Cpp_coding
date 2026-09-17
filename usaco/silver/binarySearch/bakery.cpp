#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct F {
    ll a, b, c;
};

//true math floor and ceil rather than int div that truncates to 0

ll floor_div(ll n, ll d) {
    if (n >= 0) return n/d;
    return(n-d+1)/d;
}

ll ceil_div(ll n, ll d) {
    if (n >= 0) return (n+d-1)/d;
    return n/d;
}

bool check(ll k, ll tc, ll tm, const vector<F>& friends) {
    ll s = tc+tm-k;
    ll l = max(1LL, s - tm);
    ll r = min(tc, s-1);

    for (const auto& f:friends) {
        ll diff = f.a -f.b;
        ll limit = f.c - f.b * s;

        if (diff > 0) {
            r = min(r, floor_div(limit, diff));
        } else if (diff < 0) {
            l = max(l, ceil_div(-limit, -diff));
        } else {
            if (limit < 0) return false;
        }
    }
    return l <= r;


}

void solve() {
    int n;
    ll tc, tm;
    cin >> n >> tc >> tm;

    vector<F> friends(n);
    for (int i = 0; i < n; i++) {
        cin >> friends[i].a >> friends[i].b >> friends[i].c;
    }

    ll low = 0, high = tc + tm - 2, ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, tc, tm, friends)) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}