#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        pq.push(d);
    }

    ll total_cost = 0;

    while (pq.size() > 1) {
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        ll m = first+second;
        total_cost += m;
        pq.push(m);
    }
    cout << total_cost;
    return 0;
}