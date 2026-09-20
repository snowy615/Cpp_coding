#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;
const int OFFSET = 1e4;
const int MAX_COORD = 2e5+5;

struct point {
    ll val;
    int id;

    bool operator<(const point& other) const {
        return val < other.val;
    }
};

vector<point> lines_y[MAX_COORD];
vector<point> lines_x[MAX_COORD];

ll sum_x[100005];
ll sum_y[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lines_y[y + OFFSET].push_back({x,i});
        lines_x[x+OFFSET].push_back({y,i});
    }

    //s_x for all points
    for (int y = 0; y < MAX_COORD; y++) {
        if (lines_y[y].empty()) continue;

        sort (lines_y[y].begin(), lines_y[y].end());
        int m = lines_y[y].size();
        ll cur_sum = 0;
        for (int i = 1; i < m; i++) {
            cur_sum += lines_y[y][i].val - lines_y[y][0].val;
        }
        sum_x[lines_y[y][0].id] = cur_sum;

        for (int i = 1; i < m; i++) {
            ll diff = lines_y[y][i].val - lines_y[y][i-1].val;
            cur_sum += i*diff - (m-i) * diff;
            sum_x[lines_y[y][i].id] = cur_sum;
        }

    }

    //s_y
    for (int x = 0; x < MAX_COORD; x++) {
        if (lines_x[x].empty()) continue;

        sort(lines_x[x].begin(), lines_x[x].end());
        int m = lines_x[x].size();

        ll cur_sum = 0;
        for (int i = 1; i < m; i++) {
            cur_sum += lines_x[x][i].val - lines_x[x][0].val;
        }
        sum_y[lines_x[x][0].id] = cur_sum;

        for (int i = 1; i < m; i++) {
            ll diff = lines_x[x][i].val - lines_x[x][i-1].val;
            cur_sum += i * diff - (m-i) * diff;
            sum_y[lines_x[x][i].id] = cur_sum;
        }

    }

    ll total_area_sum = 0;
    for (int i = 0; i < n; i++) {
        ll anchor_triangle = (sum_x[i] % MOD) * (sum_y[i] % MOD) % MOD;
        total_area_sum = (total_area_sum + anchor_triangle) % MOD;
    }
    cout << total_area_sum;
    return 0;

}