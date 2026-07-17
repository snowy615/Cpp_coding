#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int sorted_suffix_len = 1;
    for (int i = n-2; i >= 0; i--) {
        if (p[i] < p[i+1]) sorted_suffix_len ++;
        else break;
    }
    cout << n-sorted_suffix_len;
    return 0;
}