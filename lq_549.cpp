#include <iostream>
using namespace std;
const int N=110;
int n, m;
int lis[N][N];
int new_lis[N][N];
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    cin >> n >> m;
    for (int i = 0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> lis[i][j];
            new_lis[i][j] = lis[i][j];
        }
    }


    for (int i = 0; i<n; i++){
        for (int j=0; j<m; j++){
            if (lis[i][j] == 1) new_lis[i][j] = 9;
            else{
                for (int v=0; v<8; v++){
                    if (i+x[v]>=0 && i+x[v]<=n && j+y[v]>=0 && j+y[v]<=m && lis[i+x[v]][j+y[v]]==1) new_lis[i][j] ++;
                    //cout << "i, j " << i << " " << j << " x[v] y[v]" << x[v] << " " << y[v] << "\n";
                }
            }
        }
    }
    for (int i = 0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << new_lis[i][j] << " ";
        }
        cout << "\n";
    }
}
