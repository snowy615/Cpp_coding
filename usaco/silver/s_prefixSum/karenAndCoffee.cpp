#include <bits/stdc++.h>
using namespace std;
const int max_tmp = 200005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diff(max_tmp, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] ++;
        diff[r+1] --;
    }

    for (int i = 1; i <= max_tmp; i++) {
        diff[i] += diff[i-1]; //actual count
    }

    vector<int> adm_p(max_tmp, 0);
    for (int i = 1; i <= max_tmp; i++) {
        int is_adm = (diff[i] >= k) ? 1: 0;
        adm_p[i] = adm_p[i-1] + is_adm;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << adm_p[b] - adm_p[a-1] << "\n";
    }

    return 0;
}