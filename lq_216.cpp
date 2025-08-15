#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;
int n, m, k;

int cx[2] = {1, 0};
int cy[2] = {0, 1};
const int N = 55;

ll mm[N][N];
ll dp[N][N][15][15];
ll d = 1e9+7;

ll test(int x, int y, ll mx, int cnt){
    ll res = 0;
    if (x == n && y == m) return (ll) (cnt==k);
    if (dp[x][y][mx][cnt]!=-1) return dp[x][y][mx][cnt] % d;

    for (int i=0; i<2; i++){
        int xx = cx[i]+x;
        int yy = cy[i]+y;
        if (xx > 0 && xx <= n && yy > 0 && yy<=m){
            res = (res+test(xx, yy, mx, cnt))%d;
            if (mm[xx][yy] > mx && cnt < k) {
                res = (res + test(xx, yy, mm[xx][yy], cnt+1))%d;
            }
        } else continue;
    }
    return dp[x][y][mx][cnt] = res;

}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> mm[i][j];
            mm[i][j] ++;
        }
    }
    cout << (test(1, 1, 0, 0) + test(1,1,mm[1][1], 1))%d;
}