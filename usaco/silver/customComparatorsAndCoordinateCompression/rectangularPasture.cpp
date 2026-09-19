#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int P[2505][2505];

struct Point {
    int x, y;
};

int query(int x1, int x2, int y1, int y2) {
    return P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    //coordinate compression sort, then assign rank first y, then x

    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    for (int i = 0; i < n; i++) pts[i].y = i+1;
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    for (int i = 0; i < n; i++) pts[i].x = i+1;

    //2D prefix sum array
    for (int i = 0; i < n; i++) {
        P[pts[i].x][pts[i].y] = 1; // mark location
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            P[i][j] += P[i-1][j] + P[i][j-1] - P[i-1][j-1];
        }
    }

    ll ans = 1; //empty subset
    //iterate over pairs of cows
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int y1 = min(pts[i].y, pts[j].y);
            int y2 = max(pts[i].y, pts[j].y);

            int x1 = pts[i].x;
            int x2 = pts[j].x;

            int top_cows = query(x1, x2, y2, n);
            int bottom_cows = query(x1, x2, 1, y1);
            ans += 1LL * top_cows * bottom_cows;
        }
    }
    cout << ans;
    return 0;

}