#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//(bi1+i1) + bi2 + (bi3-i3), where l = i1, r = i3
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<ll> pref(n, 0);
        pref[0] = b[0];
        for (int i = 1; i < n; i++) pref[i] = max(pref[i-1], b[i] + i);

        vector<ll> suff(n, 0);
        suff[n-1] = b[n-1] - (n-1);
        for (int i = n-2; i >= 0; i--) suff[i] = max(suff[i+1], b[i] - i);

        ll max_b = 0;
        for (int j = 1; j < n - 1; j++) {
            ll cur_score = pref[j-1] + b[j] + suff[j+1];
            max_b = max(max_b, cur_score);
        }

        cout << max_b << "\n";
    }

}