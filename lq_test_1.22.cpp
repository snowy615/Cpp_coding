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
    for (int bit = 0; bit <= 20; bit++){
        int cnt0 = 0, cnt1 = 0;
        for (int i=0; i<=n; i++){
            if (pre[i] & (1<<bit)) cnt1 ++;
            else cnt0 ++;
        }
        s += cnt0*cnt1 * (1 << bit);
    }
    cout << s;
}