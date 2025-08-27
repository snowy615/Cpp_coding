#include <iostream>
using namespace std;
const int N = 1e2+5;
int a[N][N], b[N][N], c[N][N];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=1; i <= n; i++){
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=k; j++) cin >> b[i][j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            for (int h=1; h<=m; h++){
                c[i][j] += a[i][h] * b[h][j];
            }
            cout << c[i][j] << ' ';
        }
        cout << "\n";
    }

}