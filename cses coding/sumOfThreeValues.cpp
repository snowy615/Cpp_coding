#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct E {
    ll val;
    int id;
    bool operator<(const E& other) const {
        return val < other.val;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll x;
    cin >> n >> x;

    vector<E> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].id = i+1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i ++) {
        int left=  i+1;
        int right = n-1;
        ll target = x - a[i].val;

        while (left < right) {
            ll cur_sum = a[left].val + a[right].val;
            if (cur_sum == target) {
                cout << a[i].id << " " << a[left].id << " " << a[right].id << "\n";
                return 0;
            } else if (cur_sum < target) left ++;
            else right --;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}