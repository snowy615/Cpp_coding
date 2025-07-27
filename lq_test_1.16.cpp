#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
ll k, n, vv,tt;
vector<pair<ll, ll>> v;

int main(){
    cin >> k >> n;
    for (int i=1; i<=k; i++){
        cin >> vv >> tt;
        v.push_back({vv, tt});
    }
    ll t_max = 0;
    for (int i=1; i<=n; i++){
        ll cur_min = 1e15;
        for (int j=1; j<=k; j++){
            ll cur = abs(i-v[j].first) + v[j].second;
            if (cur < cur_min) cur_min = cur;
        }
        t_max = max(t_max, cur_min);
    }
    cout << t_max;
    return 0;
}