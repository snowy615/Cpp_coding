#include <iostream>
#define int long long
using namespace std;

const int p = 1e9+7, N = 5e5+5;

int fac[N];
int qmi(int a, int b){
    int res = 1;
    while (b){
        if (b&1) res = res*a%p;
        a = a*a%p;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return qmi(x, p-2);
}

int cnr(int n, int m){
    if (n<0 || m < 0 || n<m) return 0;
    return fac[n] * inv(fac[m]*fac[n-m]%p) % p;
}

signed main(){
    int n, m;
    cin >> n >> m;
    fac[0] = 1;
    for (int i=1; i<=m; i++) fac[i] = fac[i-1] * i % p;
    int ans = cnr(m,n) * fac[n] %p;
    int tmp=0;
    for (int i=1; i<=n; i++){
        tmp += ((i&1) ? 1:-1) * cnr(n, i)%p * cnr(m-i, n-i)%p*fac[n-i]%p;
        tmp = (tmp%p+p)%p;
    }
    ans = (ans*(ans-tmp)%p+p)%p;
    cout << ans << "\n";
    return 0;
}

