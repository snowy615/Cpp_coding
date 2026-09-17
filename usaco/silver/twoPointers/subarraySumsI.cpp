#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int left=0, cnt = 0;
    ll cur_sum = 0;

    for (int right = 0; right < n; right++) {
        cur_sum += a[right];
        while (cur_sum > x && left <= right) {
            cur_sum -= a[left];
            left++;
        }
        if (cur_sum == x) cnt ++;
    }

    cout << cnt;
    return 0;

}