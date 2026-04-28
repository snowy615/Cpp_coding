#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i<n; i++){
        cin >> r[i];
    }

    int min_total_dis = 1e9;
    for (int i = 0; i < n; i++){ // for all rooms unlock
        int cur_dis = 0;
        for (int j = 0; j < n; j++){
            int target_room = (i+j) %n;
            cur_dis += j * r[target_room];
        }
        min_total_dis = min(min_total_dis, cur_dis);
    }
    cout << min_total_dis;
    return 0;
}