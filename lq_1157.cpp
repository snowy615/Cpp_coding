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


signed main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int inv = qmi(n, p-2);
        cout << inv << "\n";
    }
    return 0;
}