#include <iostream>
#define int long long
using namespace std;
const int N = 4e6+5, M = 1e5+5;
int a[M], e[N];
int son[N][2], tot = 1;


int query(int x){
    int o = 1;
    int res = 0;
    for (int i = 30; i>=0; i--){
        int y = x >> i & 1;
        if (y == 0) {
            res += e[son[o][1]];
        }
        if (!son[o][y]){
            break;
        }
        o = son[o][y];

    }
    return res;
}

void insert(int x){
    int o = 1;
    e[o] ++;
    for (int i=30; i>=0; i--){
        int y = x >> i & 1;
        if (!son[o][y]) son[o][y] = ++ tot;
        o = son[o][y];
        e[o] ++;
    }

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans += query(a[i]);
        insert(a[i]);
    }
    cout << ans << '\n';
    return 0;
}