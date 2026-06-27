#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> p(n);
    ll total_weight = 0;
    for (int i = 0; i < n; i++){
        cin >> p[i];
        total_weight += p[i];
    }
    ll min_dif = total_weight;
    //iterate through all 2^n possible subsets using bitmask
    for (int i = 0; i < (1 << n); i++){
        ll cur_sum = 0;
        for (int j = 0; j < n; j++){
            if ((i >> j) & 1) cur_sum += p[j];
        }
        ll dif = abs((total_weight-cur_sum)-cur_sum);
        min_dif = min(min_dif, dif);
        if (min_dif == 0) break;
    }
    cout << min_dif;
    return 0;
}