#include <iostream>
#include <cmath>

using namespace std;

int arr[5][5] = {1, 0, 1, 0, 1};
int path[10];
int ans;
bool check(int* path){
    int n = 0;
    for (int i=1, m=4; i<=4; i++, m--){
        for (int j=0; j<m; j++){
            int a = arr[i-1][j];
            int b = arr[i-1][j+1];
            if (path[n] == 0) arr[i][j] = a&b;
            else if (path[n] == 1) arr[i][j] = a|b;
            else arr[i][j] = a^b;
            n ++;
        }
    }
    if (arr[4][0] == 1) return true;
    return false;
}

void dfs(int depth){
    if (depth == 10){
        if (check(path)) ans ++;
        return;
    }
    for (int i=0; i<3; i++){
        path[depth] = i;
        dfs(depth+1);
    }
}

int main(){
    dfs(0);
    cout << ans;
}
