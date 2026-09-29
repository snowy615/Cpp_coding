#include <bits/stdc++.h>
using namespace std;

int parent[100005], sz[100005];

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a,b);
    }

    vector<int> reps;
    for (int i =1; i <= n; i++) {
        if (find(i) == i) reps.push_back(i);
    }

    int k = (int) reps.size() - 1;
    cout << k << "\n";

    for (int i = 0; i < k; i++) {
        cout << reps[i] << " " << reps[i+1] << "\n";
    }

    return 0;
}