#include <iostream>
#include <map>
#define int long long
using namespace std;
int n, n1, n2, x, ans = 0;
int num1[19];
int num2[19];
map<int, int> m;
void dfs1(int i, int s){
    if (i>=n1){
        m[s] ++;
        return;
    }
    dfs1(i+1, s);
    dfs1(i+1, s+num1[i]);
}
void dfs2(int i, int s){
    if (i>=n2){
        ans += m[x-s];
        return;
    }
    dfs2(i+1, s);
    dfs2(i+1, s+num1[i]);
}

signed main(){
    cin >> n >> x;
    n1 = n/2;
    n2 = n-n1;
    for (int i=1; i<=n1; i++) cin >> num1[i];
    for (int i=1; i<=n2; i++) cin >> num2[i];
    dfs1(1, 0);
    dfs2(1, 0);
    if (ans) cout << "Y";
    else cout << "N";
    return 0;
}
