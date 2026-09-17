#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    vector<int> L(n, 0);
    int j = 0;// double pointer, j -> i \_/ find min at j, j+1
    for (int i = 1; i < n; i++) {
        while (j+1 < i && L[j+1] + 1 <= x[i] - x[j+1]) j++;
        L[i] = max(x[i] - x[j], L[j] + 1);
        if (j+1 < i) L[i] = min(L[i], max(x[i] - x[j+1], L[j+1]+1));
    }

    vector<int> R(n, 0);
    j = n - 1;
    for (int i = n-2; i >= 0; i--) {
        while (j-1 > i && R[j-1] + 1 <= x[j-1] - x[i]) j--;
        R[i] = max(x[j] - x[i], R[j] + 1);
        if (j-1 > i) R[i] = min(R[i], max(x[j-1] - x[i], R[j-1] + 1));
    }

    double ans = 2e9;

    for (int i = 0; i < n; i++) ans = min(ans, (double)max(L[i], R[i])); // cow on hay

    //cow between hay i and j
    j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        while (j+1 < n) {
            double val1 = max((x[j] - x[i]) / 2.0, (double)R[j] + 1.0);
            double val2 = max((x[j+1] - x[i])/2.0, (double)R[j+1] + 1.0);

            if (val2 <= val1) j++;
            else break;
        }

        ans = min(ans, max({(x[j] - x[i])/2.0, (double) L[i] + 1.0, (double) R[j] + 1.0}));

        if (j+1 < n) {
            ans = min(ans, max({(x[j+1] - x[i]) / 2.0, (double) L[i] + 1.0, (double) R[j+1] + 1.0}));
        }

    }

    cout << fixed << setprecision(1) << ans << "\n";

}