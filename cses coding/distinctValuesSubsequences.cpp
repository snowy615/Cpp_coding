#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//(product of (cnt+1)) -1
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 1;
    ll MOD = 1e9+7;

    int cur_cnt = 1;
    for (int i = 1; i<n; i++){
        if (a[i] == a[i-1]) cur_cnt ++;
        else {
            ans = (ans * (cur_cnt+1))%MOD;
            cur_cnt = 1;
        }
    }

    if (n>0) ans = (ans * (cur_cnt + 1)) % MOD;
    ans = (ans-1+MOD)%MOD;
    cout << ans << "\n";
    return 0;

}