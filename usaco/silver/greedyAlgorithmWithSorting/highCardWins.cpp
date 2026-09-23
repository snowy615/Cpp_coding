#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n;
    cin >> n;

    vector<bool> ehas(2*n+1, false);
    vector<int> ecards(n);

    for (int i = 0; i < n; i++) {
        cin >> ecards[i];
        ehas[ecards[i]] = true;
    }

    vector<int> bcards;
    bcards.reserve(n);
    for (int i =1; i <= 2*n; i++) {
        if (!ehas[i]) bcards.push_back(i);
    }

    sort(ecards.begin(), ecards.end());

    int b_idx = 0;
    int e_idx = 0;
    int points = 0;

    while (b_idx < n && e_idx < n) {
        if (bcards[b_idx] > ecards[e_idx]) {
            points++;
            b_idx++;
            e_idx++;
        } else {
            b_idx++;
        }
    }
    cout << points << "\n";
    return 0;

}