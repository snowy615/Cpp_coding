#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, x;
    ll m = 1e9+7;
    cin >> n >> x;
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    vector<ll> coin(n);
    for (int i=0; i<n; i++) {
        ll v;
        cin >> v;
        coin[i] = v;
    }
    for (int i=0; i<=x; i++){
        for (int j=0; j<n; j++){
            if (i-coin[j] >= 0) dp[i] = (dp[i] + dp[i-coin[j]]) % m;
        }
    }
    cout << dp[x];
    return 0;
}

