#include <iostream>
using namespace std;
int n, a, b;
const int p = 1e9+7;

int qmi(int aa, int bb){
    int res = 1;
    while (bb){
        if (bb&1) res = res*aa%p;
        aa = aa * aa %p;
        bb >>= 1;
    }
    return res;
}

int ncr(int aa, int r){
    for (int i=1; i<=r; i++) {
        aa/=i;
    }
    for (int i=1; i<=(n-r); i++) {
        aa/=i;
    }
    return aa;
}

int mo(int x) {
    return (x%p+p)%p;
}

int main(){
    cin >> n >> a >> b;
    int ans = 1;
    for (int i=1; i<=n; i++) {
        ans = ans*i%p;
    }
    cout << mo(qmi(2, n)-ncr(ans, a)-ncr(ans, b)-1);
}