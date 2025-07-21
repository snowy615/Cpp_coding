#include <iostream>
using namespace std;
const int N = 500;
int n, m, c,t;
int a[N][N];
int s;
int xa, ya, xb, yb, z;
int main(){

    cin >> n >> m >> c;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cin >> t;
    for (int i=1; i<=t; i++){
        s = 0;
        cin >> xa >> ya >> xb >> yb >> z;
        if (z>c) z%=c;
        for (int j=ya; j<=yb; j++){
            cout << "\n new part s " << a[xb]-a[xa-1];
            s += a[j][xb]-a[j][xa-1];
        }
        s -= (xb-xa+1)*(yb-ya+1)*z;
        cout << s << "\n";
    }

}