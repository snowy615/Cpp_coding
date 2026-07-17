#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int cur_time = 0;
    for (int i = 0; i < n; i++) {
        if (cur_time < cows[i].first) {
            cur_time = cows[i].first;
        }
        cur_time += cows[i].second;
    }
    cout << cur_time << "\n";
    return 0;
}