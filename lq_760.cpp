#include <iostream>
using namespace std;
int n;
int res = 0;
int dfs(int num){
    if (num <= 1) {
        res ++;
        return 1;
    }
    for (int i=0; i<=num/2; i++) dfs(i);
    return 1;
}

int main(){
    cin >> n;
    dfs(n);
    cout << res;
    return 0;
}