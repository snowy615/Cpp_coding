#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    vector<vector<int>> pos(k, vector<int>(n+1));
    for (int i = 0; i < k; i++){
        for (int j = 0; j< n; j++){
            int cow;
            cin >> cow;
            pos[i][cow] = j;
        }
    }
    int consistent_pairs = 0;
    for (int ca = 1; ca <= n; ca++){
        for (int cb = 1; cb <= n; cb++){
            if (ca == cb) continue;
            bool a_better = true;
            for (int i = 0; i < k; i++){
                if (pos[i][ca] > pos[i][cb]){
                    a_better = false;
                    break;
                }
            }
            if (a_better) consistent_pairs++;
        }
    }
    cout << consistent_pairs;
    return 0;
}