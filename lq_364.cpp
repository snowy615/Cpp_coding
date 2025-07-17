#include <iostream>
using namespace std;
const int N=1e5;
int l, m, n;
int a[N];
int ls, cnt;
int mid;

int check(){
    ls = 0, cnt = 0;
    for (int i = 1; i<=n; i++){
        if (a[i]-a[ls] < mid) cnt ++;
        else ls = i;
    }
    if (l-a[n] < mid) cnt ++;
    return cnt;
}
int main(){
    a[0] = 0;
    cin >> l >> n >> m;
    for (int i = 1; i<=n; i++) cin >> a[i];
    int ll = 0, rr = 1e9+1;
    while(ll+1!=rr){
        mid = (ll+rr)>>1;
        if (check() <=m) ll = mid;
        else rr = mid;
    }
    cout << ll;

}