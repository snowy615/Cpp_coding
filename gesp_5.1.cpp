#include <iostream>
#define int long long

using namespace std;
int a,b,n,m;
int ma, mb, nb, tmp;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> a >> b;

    if (a>b) {
        tmp = a;
        a=b;
        b=tmp;
    }
    if (m>n) {
        tmp = m;
        m=n;
        n=tmp;
    }

    int cnt = 0;
    for (int i=0; i<=m/b; i++){
        mb = i; //na
        ma = (m-mb*b)/a;
        nb = (n-mb*a)/b;
        if (ma>nb) ma = nb;
        if (mb+ma>cnt) cnt = ma+mb;
//        cout << ma+mb << " " << ma << " " << mb;
//        cout << " " << ma*a+mb*b << " " << ma*b+mb*a << "\n";
    }
    cout << cnt;
}