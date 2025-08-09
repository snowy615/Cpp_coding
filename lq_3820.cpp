#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int sx, sy, fx, fy;
int cx[4] = {1, -1, 0, 0};
int cy[4] = {0, 0, -1, 1};
const int N = 1e3+5;
int dp[N][N];
int mm[N][N][2];

bool test(int x, int y, int t){
    if (mm[x][y][t] != -1) return mm[x][y][t];
    if (x == fx && y == fy) {
        mm[x][y][t] = 1;
        return true;
    }
    for (int i=0; i<4; i++){
        int xx = cx[i]+x;
        int yy = cy[i]+y;
        if (xx > 0 && xx <= n && yy > 0 && yy<=m){
            if (dp[x][y] > dp[xx][yy] && test(xx, yy, t)) {
                mm[x][y][t] = 1;
                return true;
            }
            if (!t && dp[x][y]+k > dp[xx][yy] && test(xx, yy, 1)) {
                mm[x][y][1] = 1;
                return true;
            }
        }

    }
    mm[x][y][t] = 0;
    return false;
}

int main(){
    memset(mm, -1, sizeof mm);
    cin >> n >> m >> k;
    cin >> sx >> sy >> fx >> fy;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
        }
    }
    if (test(sx, sy, 0)) cout << "Yes";
    else cout << "No";
}