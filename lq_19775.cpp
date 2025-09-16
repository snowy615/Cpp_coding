#include <iostream>
#define int long long
using namespace std;
const int p = 1e9+7;

const int N = 1e7+5;
int fac[N], invfac[N];

int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b&1) res = res * a %p;
        a = a*a% p;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return qmi(x, p-2);
}

void init(){
    int x = 1e7;
    fac[0]=1;
    for (int i=1; i<=x; i++) fac[i] = fac[i-1]*i%p;
    invfac[x] = inv(fac[x]);
    for (int i=x-1; i>=0; i--) invfac[i] = invfac[i+1]*(i+1)%p;
}

int combo(int n, int m){
    return fac[n]%p * invfac[m]%p * invfac[n-m]%p;

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, m, n;
    cin >> q;
    init();
    while (q--){
        cin >> n >> m;
        cout << combo(n, m) << "\n";
    }
    return 0;
}