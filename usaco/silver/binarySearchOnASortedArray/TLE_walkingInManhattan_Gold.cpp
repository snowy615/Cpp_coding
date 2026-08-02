#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> h_roads, v_roads;
    for (int i = 0; i < n; i++) {
        char type;
        ll c;
        cin >> type >> c;
        if (type == 'H') h_roads.push_back(c);
        else v_roads.push_back(c);
    }

    sort(h_roads.begin(), h_roads.end());
    sort(v_roads.begin(), v_roads.end());

    for (int i = 0; i < q; i++) {
        ll x, y, d;
        cin >> x >> y >> d;

        bool on_v = binary_search(v_roads.begin(), v_roads.end(), x);
        bool on_h = binary_search(h_roads.begin(), h_roads.end(), y);

        int dir;
        if (on_v && on_h) dir = 0; // N
        else if (on_v) dir = 0;
        else dir = 1;

        ll total_time = 0;

        while (d > 0) {
            if (dir == 0) {
                auto it = upper_bound(h_roads.begin(), h_roads.end(), y);
                if (it == h_roads.end()) {
                    y += d;
                    d = 0;
                }else {
                    ll next_y = *it;
                    ll dist = next_y - y;
                    if (d >= dist) {
                        d -= dist;
                        y = next_y;
                        total_time += dist;
                        dir = (total_time%2 == 0) ? 0:1;
                    }else {
                        y += d;
                        d = 0;
                    }
                }
            }else {
                auto it = upper_bound(v_roads.begin(), v_roads.end(), x);
                if (it == v_roads.end()) {
                    x += d;
                    d = 0;
                } else {
                    ll next_x = *it;
                    ll dist = next_x - x;
                    if (d >= dist) {
                        d -= dist;
                        x = next_x;
                        total_time += dist;
                        dir = (total_time%2==0) ? 0:1;
                    }else {
                        x += d;
                        d = 0;
                    }
                }
            }
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}