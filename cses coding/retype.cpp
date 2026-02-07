#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;

    vector<pair<long long,int>> events;
    events.reserve(2*n);
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        // +1 for arrival, -1 for leaving
        events.emplace_back(a, 1);
        events.emplace_back(b, -1);
    }

    // Sort by time; if times equal, process -1 (leave) before +1 (arrive)
    sort(events.begin(), events.end(), [](const auto &x, const auto &y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second; // -1 before +1
    });

    int current = 0;
    int best = 0;
    for (auto &ev : events) {
        current += ev.second;
        best = max(best, current);
    }

    cout << best << '\n';
    return 0;
}
