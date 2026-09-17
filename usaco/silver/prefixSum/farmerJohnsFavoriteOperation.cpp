#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//median of the circle (cut circle at every place)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= m;
        }
        sort(a.begin(), a.end());

        vector<ll> b(2*n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
            b[i+n] = a[i] + m;
        }

        vector<ll> pref(2*n+1, 0);
        for (int i = 0; i < 2*n; i++) {
            pref[i+1] = pref[i] + b[i];
        }

        ll min_b = -1;
        for (int i = 0; i < n; i++) {
            int m_idx = i + n/2;
            ll med = b[m_idx];

            ll left_cnt = m_idx - i;
            ll left_sum = pref[m_idx] - pref[i];
            ll left_cost = (left_cnt * med) - left_sum;

            ll right_cnt = (i+n-1) - m_idx;
            ll right_sum = pref[i+n] - pref[m_idx+1];
            ll right_cost = right_sum - (right_cnt * med);

            ll total_cost = left_cost + right_cost;

            if (min_b == -1 || total_cost < min_b) min_b = total_cost;

        }
        cout << min_b << "\n";
    }
    return 0;
}