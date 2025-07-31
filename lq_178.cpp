#include <iostream>
using namespace std;
const int N = 1001;
int n, idx=0;
char mp[N][N];
int color[N][N], color_f[N];
int x[4]= {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

void dfs(int xx, int yy){
    color[xx][yy]=idx;
    for (int z = 0; z<4; z++){
        int xxx = xx + x[z];
        int yyy =  yy+y[z];
        if (mp[xxx][yyy] == '.' || color[xxx][yyy]) continue;
        dfs(xxx, yyy);
    }
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> mp[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (mp[i][j] == '.' || color[i][j]) continue;
            idx ++;
            dfs(i, j);

        }

    }
    int cnt = 0;

    for (int i =1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (mp[i][j] == '.') continue;
            bool t = true;
            for (int z = 0; z<4; z++){
                int xx = i+x[z];
                int yy = j+y[z];
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && mp[xx][yy] == '.') t = false;
            }
            if (t){
                if (!color_f[color[i][j]]) cnt ++;
                color_f[color[i][j]] = 1;
            }
        }
    }
    cout << idx-cnt;
    return 0;

}