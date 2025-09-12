#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a,b,n,m;

signed main(){
    cin >> n >> m;
    cin >> a >> b;

    if (a>b) swap(a, b);
    if (m>n) swap(m, n);

    int cnt = 0;
    for (int i=0; i<=m/b; i++){
        int mb = i; //na
        int ma = (m-mb*b)/a;
        int nb = (n-mb*a)/b;
        cnt = max(cnt, mb+min(ma, nb));
//        cout << ma+mb << " " << ma << " " << mb;
//        cout << " " << ma*a+mb*b << " " << ma*b+mb*a << "\n";
    }
    cout << cnt;
}