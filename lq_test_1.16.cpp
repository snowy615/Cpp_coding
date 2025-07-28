#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, len, vv,tt;
vector<pair<ll, ll>> num;
vector<pair<ll, ll>> x;

bool check(int t){
    x.clear();
    for (int i=0; i<n; i++) {
        if (num[i].second <= t) {
            ll nl = max(1ll, num[i].first - (t - num[i].second));
            ll nr = min(len, num[i].first + (t - num[i].second));
            x.push_back({nl, nr});
        }

    }
    sort(x.begin(), x.end());
    if (x[0].first > 1) return 0;
    ll end = x[0].second;
    for (int i=1; i<x.size(); i++){
        if (x[i].first > end+1) break;
        else end = max(end, x[i].second);
    }
    return end >= len;

}

int main(){
    cin >> n >> len;
    for (int i=0; i<n; i++){
        cin >> vv >> tt;
        num.push_back({vv, tt});
    }
    ll l = 0, r = 1e10;
    while (l+1 != r) {
        ll mid = (r-l)/2+l;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}