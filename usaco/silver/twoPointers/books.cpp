//sliding window

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_books = 0;
    int left = 0;
    ll cur_sum = 0;

    for (int right = 0; right < n; right++) {
        cur_sum += a[right];
        while (cur_sum > t) {
            cur_sum -= a[left];
            left ++;
        }
        max_books = max(max_books, right-left+1);
    }

    cout << max_books;
    return 0;
    
}