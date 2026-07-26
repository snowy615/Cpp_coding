#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
        ll A, B;
        cin >> A >> B;
        // lower_bound finds the first element >= A
        auto left_it = lower_bound(a.begin(), a.end(), A);

        // upper_bound finds the first element > B
        auto right_it = upper_bound(a.begin(), a.end(), B);

        int cnt = distance(left_it, right_it);

        cout << cnt << "\n";

    }
    return 0;

}