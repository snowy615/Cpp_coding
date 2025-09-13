#include <iostream>
#define int long long


using namespace std;
int a,b,n,m;
bool check(int cnt){
    if (cnt <= 0) return true;
    if (a*cnt > n || a*cnt >m) return false;
    int ma = (m-a*cnt)/(b-a); //max
    int mi = 0; //min
    if (b*cnt > n) mi = (b*cnt-n+b-a-1) / (b-a);
    return max(0LL, mi) <= min(cnt, ma);
}
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
            if (check(cnt)) l = cnt;
            else r = cnt;
        }
        cout << l;
    }

}