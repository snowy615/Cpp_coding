#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    ll k;
    int n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll dis = 0;
        ll time = 0;
        ll cur_v = 1;
        while (1) {
            dis += cur_v;
            time ++;
            if (dis >= k) break;
            if (cur_v >= x) {
                dis += cur_v;
                time ++;
                if (dis >= k) break;
            }
            cur_v ++;
        }
        cout << time << "\n";

    }
    return 0;
}() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    ll k;
    int n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll dis = 0;
        ll time = 0;
        ll cur_v = 1;
        while (1) {
            dis += cur_v;
            time ++;
            if (dis >= k) break;
            if (cur_v >= x) {
                dis += cur_v;
                time ++;
                if (dis >= k) break;
            }
            cur_v ++;
        }
        cout << time << "\n";

    }
    return 0;
}