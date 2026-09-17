#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n+1, 0);
    vector<ll> p(n+1, 0);
    vector<ll> pp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i-1] + a[i];
        pp[i] = pp[i-1] + p[i];
    }

    vector<ll> b(n+1, 0);
    vector<ll> pb(n+1, 0);

    for (int i = 1; i <= n; i++) {
        ll sum_p_range = pp[n] - pp[i-1];
        ll subtract_p_prev = (n-i+1)*p[i-1];
        b[i] = sum_p_range - subtract_p_prev;
        pb[i] = pb[i-1] + b[i];
    }

    //sum of the first x elements of the array with binary search by finding full blocks, then last partial block. block 1 = n, block 2 = n-1... block n = 1

    auto sum_up_to = [&] (ll x) -> ll {
        if (x == 0) return 0;

        ll low = 0, high = n, full_blocks = 0;

        while (low <= high) {
            ll mid = low + (high-low)/2;
            ll elements_cnt = mid*n - mid*(mid-1)/2;
            if (elements_cnt <= x) {
                full_blocks = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ll total_sum = pb[full_blocks];
        ll elements_in_full_blocks = full_blocks * n - full_blocks * (full_blocks - 1) / 2;
        ll rem = x - elements_in_full_blocks;

        if (rem > 0) {
            ll start_idx = full_blocks + 1;
            ll end_idx = full_blocks + rem;
            ll sum_p_range = pp[end_idx] - pp[start_idx - 1];
            ll subtract_p_prev = rem*p[start_idx - 1];
            total_sum += (sum_p_range - subtract_p_prev);
        }
        return total_sum;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        cout << sum_up_to(r) - sum_up_to(l-1) << "\n";
    }

    return 0;


}
