#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll cur_val;
    cin >> cur_val;

    ll cur_sum = cur_val;
    ll max_sum = cur_val;

    for (int i = 1; i<n; i++){
        cin >> cur_val;
        cur_sum = max(cur_val, cur_sum + cur_val);
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum;
    return 0;
}
