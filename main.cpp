#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define int long long
int n, len;
vector<pair<int, int>> x;
struct da {
    int l, s;
} a[100005];

bool check(int t) {
    x.clear(); // 每次调用check函数时清空x，避免上次的残留数据影响
    for (int i = 1; i <= n; i++) {
        if (a[i].s <= t) {
            int nl = a[i].l - (t - a[i].s);
            int nr = a[i].l + (t - a[i].s);
            nl = max(1ll, nl); // 确保左端点不小于1
            nr = min(len, nr); // 确保右端点不大于管道长度
            x.push_back({nl, nr});
        }
    }
    sort(x.begin(), x.end());
    if (x[0].first > 1) return 0;
    int end = x[0].second;
    for (int i = 1; i < x.size(); i++) {
        if (x[i].first > end) break;
        else end = max(end, x[i].second);
    }
    return end >= len;
}

signed main() {
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        int l, s;
        cin >> a[i].l >> a[i].s;
    }
    int l = 0, r = 1e10;
    while (l + 1!= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}