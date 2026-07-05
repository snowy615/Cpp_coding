#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    while (cnt < n) {
        if (a[cnt] > x) {
            cout << cnt;
            return 0;
        }
        x -= a[cnt];
        cnt ++;
    }
    cout << n;
    return 0;
    
}