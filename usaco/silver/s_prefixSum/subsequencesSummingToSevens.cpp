#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> first_seen(7, -1);
    first_seen[0] = 0;

    int cur_mod = 0;
    int max_len = 0;

    for (int i = 1; i <= n; i++) {
        ll cow_id;
        cin >> cow_id;
        cur_mod = (cur_mod + cow_id) % 7;
        if (first_seen[cur_mod] != -1) max_len = max(max_len, i-first_seen[cur_mod]);
        else first_seen[cur_mod] = i;
    }
    cout << max_len;
    return 0;
}