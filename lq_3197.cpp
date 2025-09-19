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
    int n, m;
    cin >> n >> m;
    cout << (6*qmi(2,m) + 6*qmi(2, n)-24+p)%p;
    return 0;
}
