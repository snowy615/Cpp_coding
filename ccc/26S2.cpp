#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, l, q;
    cin >> n; //parking spots
    cin >> l; //lights
    cin >> q; //queries

    vector<int> pl(n+2, 0);
    vector<int> sl(n+2, 0);
    for (int i = 0; i < l; i++) {
        int p, s;
        cin >> p >> s;
        // cout << p << s << " \n";
        if (s == 0) {
            pl[p] ++;
            pl[p+1]--;
        }else {
            pl[max(0, p-s)] ++;
            pl[min(n+1, p+s+1)] --;
        }
        // for (int i = 0; i < n+2; i++) {
        //     cout << pl[i] << " ";
        // }
        // cout << "\n";
    }
    sl[0] = pl[0];
    for (int i = 1; i < n+2; i++) {
        sl[i] = sl[i-1]+pl[i];
    }
    // for (int i = 0; i < n+2; i++) {
    //     cout << sl[i] << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (sl[x]>0) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}