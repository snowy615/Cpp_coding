#include <iostream>
#define int long long
using namespace std;
int p = 1e9+7;
int n, m;

int qmi(int a, int b){
    int ans = 1;
    while (b){
        if (b&1) ans = ans*a%p;
        a = a*a%p;
        b >>= 1;

    }
    return ans;
}
signed main(){
    cin >> n >> m;
    int c = 1e9+7;
    int phi = c;
    for (int i=2; i <= c/i; i++){
        if (c%i) continue;
        phi = phi/i*(i-1);
        while (c%i == 0) c/=i;
    }
    if (c>1) phi = phi/c*(c-1);
    int b = 1;
    for (int i=1; i<=m; i++) {
        b = b*i %phi;
    }
    cout << qmi(n, b) << "\n";
    return 0;
}