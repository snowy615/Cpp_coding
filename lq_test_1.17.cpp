#include <iostream>
#include <algorithm>
#include <queue>
using ll = long long;
using namespace std;
const int N = 1e5+5;
ll c[N];

int main(){
    ll n, q, k, m, v;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
    }
    sort(c+1, c+n+1);

    for (int i=1; i<=q; i++){
        cin >> k >> m;
        ll lf = 0;
        int l = 1, r = n;
        while (m && l<r){
            ll cur_max = c[r];
            ll cur_min = c[l];
            if (cur_min>=k || 2*k-cur_max <= cur_min) {
                lf += 2*k-cur_max;
                r--;
            }else{
                lf += cur_min;
                l++;
            }
            m --;
        }
        cout << lf << "\n";

    }
    return 0;
}