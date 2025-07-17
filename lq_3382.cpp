#include <iostream>
#include <cmath>
using namespace std;

int mod = 1e9 + 7;
int main(){
    int n, m;
    cin >> n >> m;
    int l, r, k;
    long long a[100010], a1[100010], a2[100010], a3[100010], a4[100010], a5[100010];
    a1[0]=0;
    a2[0]=0;
    a3[0]=0;
    a4[0]=0;
    a4[0] = 0;
    a5[0] = 0;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
        if (i==1) {
            a1[i] = a[i];
            a2[i] = a[i]*a[i] % mod;
            a3[i] = a[i]*a[i]*a[i] % mod;
            a4[i] = a[i]*a[i]*a[i]*a[i] % mod;
            a5[i] = a[i]*a[i]*a[i]*a[i]*a[i] % mod;
        }
        else {
            a1[i] = (a[i] + a1[i-1])%mod;
            a2[i] = (a[i]*a[i] + a2[i-1])%mod;
            a3[i] = (a[i]*a[i]*a[i] + a3[i-1])%mod;
            a4[i] = (a[i]*a[i]*a[i]*a[i] + a4[i-1])%mod;
            a5[i] = (a[i]*a[i]*a[i]*a[i]*a[i] + a5[i-1])%mod;
        }
    }
    for (int i = 0; i<m; i++){
        cin >> l >> r >> k;
        if (k==1) cout << (a1[r]-a1[max(0, l-1)])%mod <<"\n";
        if (k==2) cout << (a2[r]-a2[max(0, l-1)])%mod << "\n";
        if (k==3) cout << (a3[r]-a3[max(0, l-1)])%mod << "\n";
        if (k==4) cout << (a4[r]-a4[max(0, l-1)])%mod << "\n";
        if (k==5) cout << (a5[r]-a5[max(0, l-1)])%mod << "\n";

    }
}