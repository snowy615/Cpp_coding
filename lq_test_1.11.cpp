#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
const int N = 1e5+5;
ll dif[N];
ll original[N], f[N];

int main(){
    int n, m;
    ll sum = 0, msum=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> original[i];
    }
    cin >> m;
    int l, r;
    for (int i=1; i<=m; i++){
        cin >> l >> r;
        dif[l] ++;
        dif[r+1] --;
    }
    for (int i=1; i<=n; i++){
        f[i] = f[i-1]+dif[i];
        //cout << f[i] << " ";
    }
//    cout << "\n";
    for (int i=1; i<=n; i++){
        sum += f[i] * original[i];
    }
//    cout << "\n";
//    cout << sum;
    sort(original+1, original+1+n);
    sort(f+1, f+1+n);
    for (int i=1; i<=n; i++){
        msum += f[i] * original[i];
    }
    cout << msum-sum;
}