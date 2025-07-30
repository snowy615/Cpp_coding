#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
const ll N = 1e5+5;
ll c[N], p[N];

int main(){
    ll n, q, k, m;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        p[i] = p[i-1] + c[i];
    }
    sort(c+1, c+n+1);

    for (int i=1; i<=q; i++){
        cin >> k >> m;

        //cheap paintings l=0, expensive paintings r=
        ll l = 0, r = m+1;
        while (l+1!=r){
            ll mid = l+r >> 1;
            if (c[mid] < 2*k-c[n-m+mid]) l = mid;
            else r = mid;
        }
        // cheap (l) + dif = (2k-c[i])
        ll lf = p[l] + 2*k*(m-l) - (p[n]-p[n-m+l]);
        cout << lf << "\n";

    }
    return 0;
}