#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p, parent;
vector<int> ea, eb, ew;

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool ok(int W) {
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < m; i++) {
        if (ew[i] >= W) {
            int a = find(ea[i]);
            int b = find(eb[i]);
            if (a != b) parent[b] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) != find(p[i])) return false; //cow at i cannot reach its position
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin >> n >> m;
    p.resize(n+1);
    parent.resize(n+1);

    bool sorted = true;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i) sorted = false;
    }
    ea.resize(m);
    eb.resize(m);
    ew.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ea[i] >> eb[i] >> ew[i];
    }
    if (sorted) {
        cout << -1;
        return 0;
    }

    int l = 1, h = 1e9;
    while (l < h) {
        int mid = l + (h-l+1)/2; // round up
        if (ok(mid)) l = mid;
        else h = mid - 1;
    }

    cout << l;
    return 0;
}