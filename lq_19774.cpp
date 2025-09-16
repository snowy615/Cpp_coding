#include <iostream>
#include <vector>
#define int long long
using namespace std;
vector<vector<int>> C;
signed main(){
    int n, m, c;
    cin >> n >> m >> c;
    C.resize(n+1);
    for (int i=0;i<=n; i++){
        C[i].resize(m+1);
        C[i][0]=1;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%c;
        }
    }
    cout << C[n][m] << "\n";
}