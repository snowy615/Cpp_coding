#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int k, int n, int t_max, const vector<int>& d) {
    priority_queue<int, vector<int>, greater<int>> pq; //min heap

    for (int i = 0; i < k; i++) pq.push(d[i]);

    for (int i = k; i < n; i++) {
        int nextTime = pq.top();
        pq.pop();
        pq.push(nextTime + d[i]);

    }

    int total_time = 0;
    while (!pq.empty()) {
        total_time = max(total_time, pq.top());
        pq.pop();
    }
    return total_time <= t_max;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    int n;
    ll t_max;
    cin >> n >> t_max;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid, n, t_max, d)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }

    }

    cout << ans;
    return 0;


}