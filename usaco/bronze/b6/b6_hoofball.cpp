#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    vector<int> target(n);
    vector<int> incoming(n, 0);

    for (int i = 0; i < n; i++) {
        if (i == 0) target[i] = 1;
        else if (i == n-1) target[i] = n-2;
        else {
            if (x[i] - x[i-1] <= x[i+1] - x[i]) target[i] = i-1;
            else target[i] = i+1;
        }
        incoming[target[i]]++;
    }

    int balls = 0;
    for (int i = 0; i < n; i++) {
        if (incoming[i] == 0) balls ++;
    }

    for (int i = 0; i < n; i++) {
        int j = target[i];
        if (i<j && target[j] == i && incoming[i] == 1 && incoming[j] == 1) balls++;
    }
    cout << balls;
    return 0;
}