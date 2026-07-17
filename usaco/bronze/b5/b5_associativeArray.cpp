#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    map<ll, ll> a;

    while (q--) {
        int t;
        cin >> t;

        if (t == 0) {
            ll k, v;
            cin >> k >> v;
            a[k] = v;
        }else if (t==1) {
            ll k;
            cin >> k;
            cout << a[k] << "\n";
        }
    }
    return 0;
}
