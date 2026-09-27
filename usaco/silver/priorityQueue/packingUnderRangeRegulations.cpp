#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (auto& [l, r]: a) cin >> l >> r;

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0, cur = 0;

    while (i < n || !pq.empty()) {
        if (pq.empty()) cur = max(cur, a[i].first);
        while (i < n && a[i].first <= cur) pq.push(a[i++].second);
        if (pq.top() < cur) {
            cout << "No\n";
            return;
        }
        pq.pop();
        cur ++;
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

}