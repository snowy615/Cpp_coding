#include <iostream>
using namespace std;

int n, m, t, k;
int grid[110][110], grid2[110][110];

int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int main(){
    int x, y;
    cin >> n >> m;
    cin >> t;
    for (int i = 0; i<t; i++){
        cin >> x >> y;
        grid[x][y] = 1;
        grid2[x][y]=1;
    }
    cin >> k;
    int ans = 0;
    for (int v=0; v<k; v++){
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=n; j++){
                for (int s = 0; s<4; s++){
                    if (1<= i+xx[s] <=n && 1<=j+yy[s]<=m) grid2[i+xx[s]][j+yy[s]] = 1;
                }
            }
        }
        for (int i = 1; i<=n; i++){
            for (int j=1; j<=n; j++){
                grid[i][j] = grid2[i][j];
            }
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (grid[i][j] == 1) ans ++;
        }
    }
    cout << ans;
}