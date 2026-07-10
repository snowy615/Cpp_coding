#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> degree(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int max_deg = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > max_deg) max_deg = degree[i];
    }

    cout << max_deg + 1;
    return 0;
}