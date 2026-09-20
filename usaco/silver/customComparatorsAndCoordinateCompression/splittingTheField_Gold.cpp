#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
    ll x, y;
};

bool compareX(const point& a, const point& b) {
    return a.x < b.x;
}

ll get_min_split_area(vector<point>& pts) {
    int n = pts.size();
    vector<ll> smin_y(n), smax_y(n);
    smin_y[n-1] = pts[n-1].y;
    smax_y[n-1] = pts[n-1].y;
    for (int i = n-2; i >= 0; i--) {
        smin_y[i] = min(smin_y[i+1], pts[i].y);
        smax_y[i] = max(smax_y[i+1], pts[i].y);
    }

    ll pmin_y = pts[0].y;
    ll pmax_y = pts[0].y;
    ll best_area = 4e18;

    for (int i = 0; i < n - 1; i++) {
        pmin_y = min(pmin_y, pts[i].y);
        pmax_y = max(pmax_y, pts[i].y);
        if (pts[i].x == pts[i+1].x) continue;

        ll area1 = (pts[i].x - pts[0].x) * (pmax_y-pmin_y);
        ll area2 = (pts[n-1].x - pts[i+1].x) * (smax_y[i+1] - smin_y[i+1]);
        best_area = min(best_area, area1+area2);
    }
    return best_area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int n;
    cin >> n;

    vector<point> pts(n);
    ll min_x = 2e9, max_x = -2e9;
    ll min_y = 2e9, max_y = -2e9;

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        min_x = min(min_x, pts[i].x);
        max_x = max(max_x, pts[i].x);
        min_y = min(min_y, pts[i].y);
        max_y = max(max_y, pts[i].y);
    }

    ll total_area = (max_x - min_x) * (max_y - min_y);
    ll min_two_area = 4e18;

    sort(pts.begin(), pts.end(), compareX);
    min_two_area = get_min_split_area(pts);

    for (int i = 0; i < n; i++) {
        swap(pts[i].x, pts[i].y);
    }
    sort(pts.begin(), pts.end(), compareX);
    min_two_area = min(min_two_area, get_min_split_area(pts));

    ll saved_area = 0;
    if (min_two_area < total_area) saved_area = total_area-min_two_area;

    cout << saved_area;
    return 0;

}