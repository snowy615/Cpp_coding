#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> cow1(n+1,0), cow2(n+1, 0), cow3(n+1, 0);
    int cow;
    for (int i = 1; i <= n; i++) {
        cin >> cow;
        cow1[i] = cow1[i-1];
        cow2[i] = cow2[i-1];
        cow3[i] = cow3[i-1];
        if (cow == 1) cow1[i]++;
        else if (cow == 2) cow2[i]++;
        else cow3[i]++;

    }
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << cow1[r]-cow1[l-1] << " " << cow2[r]-cow2[l-1] << " " << cow3[r]-cow3[l-1] << "\n";
    }




}