#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int n;
vector<ll> v;
ll tsum = 0;

ll solve(int idx, ll cur_sum){
    if (idx == n){
        ll group2_sum = tsum - cur_sum;
        return abs(cur_sum-group2_sum);
    }
    ll diff1 = solve(idx+1, cur_sum + v[idx]);
    ll diff2 = solve(idx+1, cur_sum);
    return min(diff1, diff2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    v.resize(n);
    for (int i = 0; i<n; i++){
        cin >> v[i];
        tsum += v[i];
    }
    cout << solve(0,0) << "\n";
    
    return 0;
}