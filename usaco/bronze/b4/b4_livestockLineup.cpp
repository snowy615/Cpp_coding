#include <bits/stdc++.h>
using namespace std;

vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

vector<pair<string, string>> constraints;

bool isValid() {
    for (pair<string, string> c: constraints) {
        int pos1 = find(cows.begin(), cows.end(), c.first) - cows.begin();
        int pos2 = find(cows.begin(), cows.end(), c.second) - cows.begin();
        if (abs(pos1-pos2) != 1) return false;
    }
    return true;
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i<n; i++) {
        string cow1, cow2, tmp;
        cin >> cow1 >> tmp >> tmp >> tmp >> tmp >> cow2;
        constraints.push_back({cow1, cow2});
    }
    do {
        if (isValid()) {
            for (string cow: cows) cout << cow << "\n";
            break;
        }

    }while (next_permutation(cows.begin(), cows.end()));
    return 0;

}
