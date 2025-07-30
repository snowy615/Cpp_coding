#include <iostream>
#include <algorithm>
#include <queue>
using ll = long long;
using namespace std;

priority_queue <ll> c_max;
priority_queue <ll, vector<ll>, greater<ll> > c_min;

int main(){
    ll n, q, k, m, v;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> v;
        c_max.push(v);
        c_min.push(v);
    }

    for (int i=1; i<=q; i++){
        cin >> k >> m;
        ll lf = 0;

        while (m && !c_max.empty() && !c_min.empty()){
            ll cur_max = c_max.top();
            ll cur_min = c_min.top();
            if (cur_min>=k || 2*k-cur_max <= cur_min) {
                lf += 2*k-cur_max;
                c_max.pop();
            } else{
                lf += cur_min;
                c_min.pop();
            }
            m --;
        }
        while (m && c_max.empty()){
            ll cur_min = c_min.top();
            lf += cur_min;
            c_min.pop();
            m--;
        }
        while (m && c_min.empty()){
            ll cur_max = c_max.top();
            lf += 2*k-cur_max;
            c_max.pop();
            m--;
        }
        cout << lf;
        return 0;
    }
}