#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//S_r - r = S_(l-1) - (l-1)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<int, ll> counts;
        counts[0] = 1;

        ll good = 0;
        int cur_sum = 0;

        for (int i = 0; i < n; i++) {
            cur_sum += (s[i] - '0');
            int p_i = cur_sum - (i+1);
            good += counts[p_i];
            counts[p_i]++;
        }
        cout << good << "\n";

    }
    return 0;
}