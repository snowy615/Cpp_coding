#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y, t;
};

bool compareGrazings(const Point& a, const Point& b) {
    return a.t < b.t;
}

bool canTravel(ll x1, ll y1, ll t1, ll x2, ll y2, ll t2) {
    ll dx = x1 - x2;
    ll dy = y1 - y2;
    ll dt = t1 - t2;
    return (dx * dx + dy * dy) <= (dt * dt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int g, n;
    cin >> g >> n;

    vector<Point> grazings(g);
    for (int i = 0; i < g; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }

    sort(grazings.begin(), grazings.end(), compareGrazings);

    vector<ll> grazing_times(g);
    for (int i = 0; i < g; i++) {
        grazing_times[i] = grazings[i].t;
    }

    int innocent_cnt = 0;
    for (int i = 0; i < n; i++) {
        ll cx, cy, ct;
        cin >> cx >> cy >> ct;
        bool is_innocent = false;

        auto it = lower_bound(grazing_times.begin(), grazing_times.end(), ct); //after or at

        if (it != grazing_times.end()) { //check one immediately after
            int idx = distance(grazing_times.begin(), it);
            if (!canTravel(cx, cy, ct, grazings[idx].x, grazings[idx].y, grazings[idx].t)) is_innocent = true;

        }

        if (it != grazing_times.begin()) {
            int idx = distance(grazing_times.begin(), it) - 1;
            if (!canTravel(cx, cy, ct, grazings[idx].x, grazings[idx].y, grazings[idx].t)) is_innocent = true;
        }

        if (is_innocent) innocent_cnt++;
    }
    cout << innocent_cnt;
    return 0;

}