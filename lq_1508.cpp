#include <iostream>
using namespace std;

const int N = 15;
int grid[N][N];
int n;
int ans = 0;

void dfs(int depth){
    if (depth == n+1){
        ans ++;
        return;
    }
    for (int i=1; i<=n; i++){
        if (grid[depth][i]) continue;
        for (int a=depth+1; a<=n; a++) grid[a][i] ++;
        for (int a=depth, b = i; a<=n && b>=1; a++, b--) grid[a][b] ++;
        for (int a=depth, b = i; a<=n && b<=n; a++, b++) grid[a][b] ++;

        dfs(depth+1);
        for (int a=depth+1; a<=n; a++) grid[a][i] --;
        for (int a=depth, b = i; a<=n && b>=1; a++, b--) grid[a][b] --;
        for (int a=depth, b = i; a<=n && b<=n; a++, b++) grid[a][b] --;

    }
}

int main(){
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}