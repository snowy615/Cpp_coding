#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//min heap of size k, sliding window that drops smallest element
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    if (k > n) k = n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);

        if (pq.size() > k) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;

}