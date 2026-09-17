#include <bits/stdc++.h>
using namespace std;

//tricky edge case: 1,2,3,4,10, cannot go 1,2,3,4,5 in one move cuz moved cow cannot be endpoint, so 2 moves.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int gap_left = a[1]-a[0] - 1;
    int gap_right = a[n-1] - a[n-2]-1;
    int total_empty_spaces = (a[n-1] - a[0] + 1) - n;
    int max_moves = total_empty_spaces - min(gap_left, gap_right); //max

    int min_moves = 0;
    if (a[n-2] - a[0] == n-2 && a[n-1] - a[n-2] > 2) min_moves = 2; //edge case
    else if (a[n-1] - a[1] == n-2 && a[1]-a[0] > 2) min_moves = 2;
    else {
        //normal sliding window
        int max_cows_in_w = 0;
        int right = 0;
        for (int left = 0; left < n; left++) {
            while (right + 1 < n && a[right + 1] - a[left] <= n-1) right ++;
            max_cows_in_w = max(max_cows_in_w, right-left+1);
        }
        min_moves = n - max_cows_in_w;
    }

    cout << min_moves << "\n";
    cout << max_moves << "\n";
    return 0;

}