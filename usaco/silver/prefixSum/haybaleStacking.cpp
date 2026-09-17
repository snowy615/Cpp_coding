#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> diff(n+2, 0);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b+1]--;
    }

    vector<int> heights(n);
    int cur_height = 0;
    for (int i = 1; i <= n; i++) {
        cur_height += diff[i];
        heights[i-1] = cur_height;
    }

    int median_idx = n/2;
    nth_element(heights.begin(), heights.begin()+median_idx, heights.end());
    cout << heights[median_idx];
    return 0;
}