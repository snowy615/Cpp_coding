#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int cnt = 0;
    int time_spent = 0;

    for (int i = 0; i < n; i++) {
        if (time_spent + a[i] <= x) {
            time_spent += a[i];
            cnt ++;
        }else {
            break;
        }
    }
    cout << cnt;
    return 0;
}