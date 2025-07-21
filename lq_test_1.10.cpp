#include <iostream>
using namespace std;
const int N = 500;
int n, m, c,t;
int a[N][N];
int s;
int xa, ya, xb, yb, z;
int main(){
    s = 0;
    cin >> n >> m >> c;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            s += a[i][j];
        }
    }
    cin >> t;
    cout << s << "\n";
    for (int i=1; i<=t; i++){
        cin >> xa >> ya >> xb >> yb >> z;
        if (z>c) z%=c;
        s -= (xb-xa+1)*(yb-ya+1)*z;
        cout << s << "\n";
    }

}