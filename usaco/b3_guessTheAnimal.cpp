#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<string>> animals(n);

    for (int i = 0; i < n; i++){
        string name;
        int k;
        cin >> name >> k;
        animals[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> animals[i][j];
        }
    }
    int max_common = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int cur_common = 0;
            for (const string& trait1: animals[i]){
                for (const string& trait2: animals[j]){
                    if (trait1 == trait2) cur_common ++;
                }
            }
            max_common = max(max_common, cur_common);
        }
    }
    cout << max_common + 1;
    return 0;
}