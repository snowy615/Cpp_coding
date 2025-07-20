#include <iostream>
using namespace std;
using ll = long long;
ll n,m,k;

ll check(ll mid){
    ll v = 0;
    for (ll i = 1; i<=n; i++ ) v += min(m, mid/i);
    return v;

}
int main(){
    cin >> n >> m >> k;
    ll l=0, r=1e13, mid;
    while (l+1!=r){
        mid = l+r >> 1;
        if(check(mid) < k) l=mid;
        else r=mid;
    }
    cout << r;
    return 0;

}