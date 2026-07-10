#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int E = 0;
    int O = 0;

    for (int i = 0; i < n; i++) {
        int cow_id;
        cin >> cow_id;
        if (cow_id % 2 == 0) E++;
        else O++;
    }
    for (int k = n; k >= 1; k--) {
        //o,e number of groups
        int o = k/2;
        int e = k-o;
        if (o <= O && (O-o) % 2 == 0 && e <= E + (O-o)/2) {
            cout << k;
            return 0;
        }
    }
}