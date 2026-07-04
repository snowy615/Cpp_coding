#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> cows(3);
    cin >> cows[0] >> cows[1] >> cows[2];

    sort(cows.begin(), cows.end());

    int min_moves;
    if (cows[2]-cows[0] == 2) min_moves = 0;
    else if (cows[1]-cows[0] == 2 || cows[2]-cows[1] == 2) min_moves = 1;
    else min_moves = 2;

    int left_gap_spaces = cows[1] - cows[0] - 1;
    int right_gap_spaces = cows[2] - cows[1] - 1;
    int max_moves = max(left_gap_spaces, right_gap_spaces);

    cout << min_moves << "\n";
    cout << max_moves << "\n";
    return 0;
}