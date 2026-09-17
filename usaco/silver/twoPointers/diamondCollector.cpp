#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> left_size(n, 0);
    int right = 0;

    for (int left = 0; left < n; left++) {
        while (right < n && a[right]- a[left] <= k) right ++;
        left_size[left] = right-left;
    }

    vector<int> max_after(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        max_after[i] = max(left_size[i], max_after[i+1]);
    }

    int max_total_diamonds = 0;

    for (int i = 0; i < n; i++) {
        int case1 = left_size[i];
        int case2 = max_after[i+case1];
        max_total_diamonds = max(max_total_diamonds, case1+case2);
    }
    cout << max_total_diamonds;
    return 0;


}