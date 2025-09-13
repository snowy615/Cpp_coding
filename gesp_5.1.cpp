#include <iostream>
#define int long long


using namespace std;
int a,b,n,m;
signed main(){
    cin >> n >> m;
    cin >> a >> b;
    if (a==b) cout << min(n,m)/a;
    else{
        if (a>b) swap(a,b);

        int cnt = 0;
        int l = 0, r=1e9+5;
        while (l+1<r) {
            cnt = (l + r) >> 1;
            if (((double)m - (double)a * (double)cnt) / ((double)b - (double)a) >= ((double)b * (double)cnt - (double)n) / ((double)b - (double)a)) l = cnt;
            else r = cnt;
        }
        cout << l;
    }

}