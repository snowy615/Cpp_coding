#include <iostream>
#define int long long
using namespace std;
const int p = 1e9+7;

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b&1) res = res*a%p;
        a = a*a%p;
        b >>= 1;
    }
    return res;
}

int inv(int x){
    return qmi(x, p-2);
}

signed main(){
    int n, k;
    cin >> n >> k;
    if (k==0){
        cout << 1 << "\n";
        for (int i = 2; i<=n; i++) cout << 0 << "\n";
    }else if (k&1){
        int ans = inv(n/2);
        for (int i=1; i<=n; i++){
            if (i&1) cout << 0 << "\n";
            else cout << ans << "\n";
        }
    }else {
        int ans = inv((n+1)/2);
        for (int i=1; i<=n; i++){
            if (i&1) cout << ans << "\n";
            else cout << 0 << "\n";
        }
    }
    return 0;
}