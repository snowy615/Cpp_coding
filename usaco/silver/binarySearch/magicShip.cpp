#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x1, x2, y1, y2;
int n;
string s;
vector<ll> px, py;

bool isValid(ll k) {
    ll fullCycle = k / n;
    ll rem = k%n;

    ll windX = x1 + fullCycle*px[n] + px[rem];
    ll windY = y1 + fullCycle*py[n] + py[rem];

    ll dis = abs(x2-windX) + abs(y2-windY); //Manhattan
    return dis <= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n >> s;

    px.assign(n+1, 0);
    py.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        px[i+1] = px[i] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
        py[i+1] = py[i] + (s[i] == 'U'? 1 : (s[i] == 'D' ? -1 : 0));
    }

    ll left = 1;
    ll right = 1e18;
    ll ans = -1;

    while (left <= right) {
        ll mid = left + (right-left) / 2;
        if (isValid(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}