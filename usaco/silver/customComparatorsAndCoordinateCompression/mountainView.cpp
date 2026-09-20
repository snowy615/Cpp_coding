#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct M {
    ll l, r;
};

bool compareM(const M& a, const M& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    cin >> n;

    vector<M> m(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        m[i].l = x-y;
        m[i].r = x+y;
    }

    sort(m.begin(), m.end(), compareM);

    int visible_cnt = 0;
    ll max_r = -2e9;

    for (int i = 0; i < n; i++) {
        if (m[i].r > max_r) {
            visible_cnt ++;
            max_r = m[i].r;

        }
    }

    cout << visible_cnt;
    return 0;
}