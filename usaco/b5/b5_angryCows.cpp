#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;

    vector<ll> bales(n);
    for (int i = 0; i < n; i++) {
        cin >> bales[i];
    }

    sort(bales.begin(), bales.end());

    int max_exploded = 1;

    for (int start = 0; start < n; start++) {
        int left_idx = start;
        ll radius = 1;
        while (left_idx > 0) {
            int next_left = left_idx;
            while (next_left > 0 && bales[left_idx] - bales[next_left - 1] <= radius) {
                next_left --;
            }
            if (next_left == left_idx) break;
            left_idx = next_left;
            radius++;
        }

        int right_idx = start;
        radius = 1;
        while (right_idx < n-1) {
            int next_right = right_idx;
            while (next_right < n-1 && bales[next_right+1] - bales[right_idx] <= radius) next_right++;
            if (next_right == right_idx) break;
            right_idx = next_right;
            radius++;
        }
        int cur_exploded = right_idx - left_idx + 1;
        max_exploded = max(max_exploded, cur_exploded);
    }
    cout << max_exploded << "\n";
    return 0;
}