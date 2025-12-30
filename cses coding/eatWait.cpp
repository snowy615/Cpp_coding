#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;

int main(){
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    vector<pair<ll, ll>> v;
    ll t = 0;
    ll m, n, a, b;
    cin >> m >> n;
    for (ll i=0; i<m; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (ll i=0; i<m; i++){
        a=v[i].first;
        b=v[i].second;
        t += b;
        while (pq.empty()==false && pq.top()<=a) pq.pop();
        if (pq.size()<n) pq.push(a+b);
        else{
            ll enter = pq.top();
            t += enter-a;
            pq.pop();
            pq.push(enter+b);
        }
    }
    cout << t;
}
