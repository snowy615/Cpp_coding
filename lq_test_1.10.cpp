#include <iostream>

using namespace std;
const int N = 310;
int n, m, c,t;
int a[N][N];
using ll = long long;
int cnt[N][N];
ll s;
int xa, ya, xb, yb, z;
int main(){
    cin >> n >> m >> c;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            //cout << a[i][j] << " ";
        }
        //cout << "\n";
    }
    cin >> t;
    for (int zz=1; zz<=t; zz++){
        s = 0;
        cin >> xa >> ya >> xb >> yb >> z;
        z = z % (c+1);
        for (int i=xa; i<=xb; i++){
            for (int j = ya; j<=yb; j++){
                s += a[i][j]-z;
                //cout << "r " << i << " c "<< j << "\n";
                //cout << cnt[j][i] << " " << a[j][i] << " \n";
                //cout << " "<< a[i][j]-z << "\n";
            }

        }
        cout << s << "\n";
        //cout << "----------------------------";
    }

}