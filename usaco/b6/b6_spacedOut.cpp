#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
//rows alterate horizontally
    ll max_pa = 0;
    for (int i = 0; i < n; i++) {
        ll sum_even = 0;
        ll sum_odd = 0;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) sum_even += a[i][j];
            else sum_odd += a[i][j];
        }
        max_pa += max(sum_even, sum_odd);
    }

    ll max_pb = 0;
    for (int j = 0; j < n; j++) {
        ll sum_even = 0;
        ll sum_odd = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sum_even += a[i][j];
            else sum_odd += a[i][j];
        }
        max_pb += max(sum_even, sum_odd);
    }
    cout << max(max_pa, max_pb) << "\n";
    return 0;
}