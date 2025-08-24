#include <iostream>
using namespace std;
const int N = 3e6+5, M = 1e5+5;
int a[M], prefix[M];
int son[N][2], tot = 1;


int query(int x){
    int o = 1;
    int res = 0;
    for (int i = 30; i>=0; i--){
        int y = x >> i & 1;
        if (son[o][!y]) {
            o = son[o][!y];
            res |= (1 << i);
        }else{
            o = son[o][y];
        }

    }
    return res;
}

void insert(int x){
    int o = 1;
    for (int i=30; i>=0; i--){
        int y = x >> i & 1;
        if (!son[o][y]) son[o][y] = ++ tot;
        o = son[o][y];
    }

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] ^ a[i];
    insert(0);
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, query(prefix[i]));
        insert(prefix[i]);
    }
    cout << ans << '\n';
    return 0;
}