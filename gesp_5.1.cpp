#include <iostream>
#include <algorithm>
using namespace std;
int a,b,n,m;
int ma, mb, nb;
int main(){
    cin >> n >> m;
    cin >> a >> b;

    if (a>b) swap(a, b);
    if (m>n) swap(m, n);

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