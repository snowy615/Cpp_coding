#include <iostream>
#define int long long
using namespace std;
const int N = 1e2+5;
int a[N];

void f(int n){
    for (int i=2; i<=n/i; i++){
        if (n%i) continue;
        while (n%i == 0) {
            n/=i;
            a[i] ++;
        }
    }
    if (n>1) a[n] ++;
}

signed main(){
    int n = 100;
    for (int i=1; i<=n; i++) f(i);
    int ans = 1;
    for (int i=1; i<=n; i++) ans *= (a[i]+1);
    cout << ans;
    return 0;
}

