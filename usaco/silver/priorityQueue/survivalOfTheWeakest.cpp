#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

struct Element {
    ll sum;
    int i, j;
    bool operator>(const Element& other) const {
        return sum > other.sum;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll offset = 0;
    for (int k = n; k >= 2; k--) {
        ll min_sum = a[0] + a[1];
        offset = (2LL * offset % MOD + min_sum % MOD) % MOD;
        priority_queue<Element, vector<Element>, greater<Element>> pq;

        for (int j = 1; j < k; j++) {
            pq.push({a[0] + a[j], 0, j});
        }
        vector<ll> next_a(k-1);
        for (int step = 0; step < k-1; step++) {
            Element cur = pq.top();
            pq.pop();
            next_a[step] = cur.sum - min_sum;
            if (cur.i + 1 < cur.j) {
                pq.push({a[cur.i+1] + a[cur.j], cur.i+1, cur.j}); //next possible pair sum
            }
        }
        a = next_a;
    }
    cout << offset;
    return 0;
}