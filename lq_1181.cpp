#include <iostream>
#define int long long
using namespace std;

int qmi(int a, int b, int p){
    int res = 1;
    while (b){
        if (b&1) res = res*a%p;
        a = a * a %p;
        b >>= 1;
    }
    return res;
}

signed main(){
    int t;
    cin >> t;
    while (t--){
        int n, m, p;
        cin >> n >> m >> p;
        cout << qmi(n, m, p) << "\n";
    }
}

