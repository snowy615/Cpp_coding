#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int half = n/2;
    vector<bool> e_has(2*n+1, false);
    vector<int> e1(half);
    vector<int> e2(half);

    for (int i = 0; i < half; i++) {
        cin >> e1[i];
        e_has[e1[i]] = true;
    }
    for (int i = 0; i < half; i++) {
        cin >> e2[i];
        e_has[e2[i]] = true;
    }

    vector<int> bcards;
    bcards.reserve(n);

    for (int i = 1; i <= 2 * n; i ++) {
        if (!e_has[i]) bcards.push_back(i);
    }

    vector<int> b2(bcards.begin(), bcards.begin()+half);
    vector<int> b1(bcards.begin()+half, bcards.end());

    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());

    int points = 0;

    int b_idx = 0;
    int e_idx = 0;

    while (b_idx < half && e_idx < half) {
        if (b1[b_idx] > e1[e_idx]) {
            points ++;
            b_idx ++;
            e_idx ++;
        }else {
            b_idx ++;
        }
    }

    b_idx = 0;
    e_idx = 0;

    while (b_idx < half && e_idx < half) {
        if (b2[b_idx] < e2[e_idx]) {
            points ++;
            b_idx ++;
            e_idx ++;
        }else {
            e_idx ++;
        }
    }
    cout << points;
    return 0;

}