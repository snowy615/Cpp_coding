#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x_coords, y_coords;
vector<int> partner;
vector<int> next_on_right;

bool has_cycle() {
    for (int start = 0; start < n; start ++) {
        int pos = start;
        for (int step = 0; step < n; step++) {
            pos = partner[pos];
            pos = next_on_right[pos];
            if (pos == -1) break;
        }
        if (pos != -1) return true;
    }
    return false;
}

int solve() {
    int i;
    for (i = 0; i<n; i++) {
        if (partner[i] == -1) break;
    }
    if (i == n) {
        if (has_cycle()) return 1;
        return 0;
    }
    int total_traps = 0;
    for (int j = i+1; j<n; j++) {
        if (partner[j] == -1) {
            partner[i] = j;
            partner[j] = i;
            total_traps += solve();
            partner[i] = -1;
            partner[j]=-1;
        }
    }
    return total_traps;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    x_coords.resize(n);
    y_coords.resize(n);
    partner.assign(n, -1);
    next_on_right.assign(n, -1);

    for (int i = 0; i<n; i++) {
        cin >> x_coords[i] >> y_coords[i];
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (x_coords[j] > x_coords[i] && y_coords[i] == y_coords[j]) {
                if (next_on_right[i] == -1 || x_coords[j]-x_coords[i] < x_coords[next_on_right[i]] - x_coords[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }

    cout << solve() << "\n";
    return 0;
}