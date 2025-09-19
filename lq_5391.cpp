#include <iostream>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int p = 1e9+7;
int ans[N];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tmp = 1;
    ans[0] = 1;
    for (int i =1; i<=5e5; i++){
        ans[i] = ans[i-1] * i %p * tmp % p;
        tmp = tmp * 2 %p;
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}