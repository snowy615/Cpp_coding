#include <iostream>

using namespace std;
#define int long long
const int N=1e5+5;
int n;
int num[N];
int pre[N];

signed main(){
    cin >> n;
    int s = 0;
    for (int i=1; i<=n; i++){
        cin >> num[i];
        pre[i] = pre[i-1] ^ num[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            s += pre[i-1]^pre[j];
        }
    }
    cout << s;
}