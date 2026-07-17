#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] > 0) {
        cout << -1;
        return 0;
    }
    a[0] = 0;

    for (int i = n-1; i >= 1; i--) {
        if (a[i] > 0) {
            int required_yesterday = a[i]-1;
            if (a[i-1] == -1) a[i-1] = required_yesterday;
            else if (a[i-1] != required_yesterday) {
                cout << -1;
                return 0;
            }
        }
    }

    int min_breakouts = 0;
    int max_breakouts = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            min_breakouts ++;
            max_breakouts ++;
        } else if (a[i] == -1) max_breakouts ++;
    }
    cout << min_breakouts << " " << max_breakouts;
    return 0;

}