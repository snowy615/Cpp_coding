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
        priority_queue <ll> cc_max = c_max;
        priority_queue <ll, vector<ll>, greater<ll> > cc_min = c_min;
        //cout << "s " << cc_max.size() << "\n";

        while (m && !cc_max.empty() && !cc_min.empty()){
            ll cur_max = cc_max.top();
            ll cur_min = cc_min.top();
            if (cur_min>=k || 2*k-cur_max <= cur_min) {
                lf += 2*k-cur_max;
                cc_max.pop();
            } else{
                lf += cur_min;
                cc_min.pop();
            }
            m --;
        }
        while (m && !cc_max.empty()){
            ll cur_max = cc_max.top();
            lf += 2*k-cur_max;
            cc_max.pop();
            m--;

        }
        while (m && !cc_min.empty()){
            ll cur_min = cc_min.top();
            lf += cur_min;
            cc_min.pop();
            m--;
        }
        cout << lf << "\n";

    }
    return 0;
}