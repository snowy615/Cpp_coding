#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s.begin(), s.end());
    int mismatches = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) mismatches ++;
    }

    int swaps = max(0, mismatches-1);
    cout << swaps;
    return 0;
}