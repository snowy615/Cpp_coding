#include <iostream>
#include <vector>
using namespace std;
const int N = 4e6+5, M = 1e5+5;
int a[M], fa[N], e[N];
int son[N][2], tot = 1;
vector<int> g[N];


int query(int x){
    int o = 1;
    int res = 0;
    for (int i = 30; i>=0; i--){
        int y = x >> i & 1;
        if (son[o][!y] && e[son[o][!y]]) {
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
    e[o] ++;
    for (int i=30; i>=0; i--){
        int y = x >> i & 1;
        if (!son[o][y]) son[o][y] = ++ tot;
        o = son[o][y];
        e[o] ++;
    }

}

void remove(int x){
    int o = 1;
    e[0] --;
    for (int i=30; i>=0; i--){
        int y = x >> i & 1;
        if (!son[o][y]) son[o][y] = --tot;
        o = son[o][y];
        e[o] --;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        cin >> fa[i];
        if (fa[i] != -1) g[fa[i]].push_back(i);
    }
    for (int i=0; i<n; i++) insert(a[i]);
    int ans = 0;
    for (int i=0; i<n; i++){
        for (const auto &y: g[i]) remove(a[y]);
        ans = max(ans, query(a[i]));
        for (const auto &y: g[i]) insert(a[y]);
    }
    cout << ans << '\n';
    return 0;
}