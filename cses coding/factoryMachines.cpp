#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll t;
    cin >> n >> t;
    vector<ll> k(n);

    for (int i = 0; i<n; i++){
        cin >> k[i];
    }
    ll low = 1;
    ll high = 1e18 * t;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high-low)/2;
        ll products = 0;
        for (int i=0; i<n; i++){
            products += mid/k[i];
            if (products >= t) break;
        }
        if (products >= t){
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
