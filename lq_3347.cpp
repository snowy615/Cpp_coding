#include <iostream>
#define int long long
using namespace std;
int n, a, b;
const int p = 1e9+7;
int mo(int x) {
    return (x%p+p)%p;
}

int qmi(int aa, int bb){
    int cnt = 1;
    while (bb){
        if (bb&1) cnt = cnt*aa%p;
        aa = aa * aa %p;
        bb >>= 1;
    }
    return mo(cnt);
}

int ncr(int r){
    int res = 1;
    for (int i=n; i>n-r; i--) {
        res = res*i%p;
    }
    for (int i=1; i<=r; i++) {
        res/=i;
    }
    return mo(res);
}


signed main(){
    cin >> n >> a >> b;
    int ans = 1;
    for (int i=1; i<=n; i++) {
        ans = ans*i%p;
    }
    cout << mo(mo(qmi(2, n)-ncr(a))-ncr(b)-1);
}