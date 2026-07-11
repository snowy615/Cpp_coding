#include <bits/stdc++.h>
using namespace std;

//tree, outdegree = 0, exactly 1 it is that, if >1 then impossible

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> out_deg(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        out_deg[a]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (out_deg[i] == 0) {
            if (ans != -1) {
                cout << -1;
                return 0;
            }
            ans = i;
        }
    }
    cout << ans;
    return 0;
}