#include <bits/stdc++.h>
using namespace std;

//reachable intervals must overlap, max left < min right

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<double> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double left = 0.0;
    double right = 1e9;

    for (int iter = 0; iter < 100; iter++) {
        double mid = left + (right - left) / 2.0;
        double max_l = -1e18;
        double min_r = 1e18;

        for (int i = 0; i < n; i ++) {
            double l = x[i] - v[i] * mid;
            double r = x[i] + v[i] * mid;
            if (l > max_l) max_l = l;
            if (r < min_r) min_r = r;
        }
        if (max_l <= min_r) right = mid;
        else left = mid;

    }

    cout << fixed << setprecision(12) << right;
    return 0;

}