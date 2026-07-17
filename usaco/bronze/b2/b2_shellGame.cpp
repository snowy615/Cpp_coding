#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n, a, b, g;
    cin >> n;
    vector<int> shell(4);
    shell[1] = 1, shell[2] = 2; shell[3]=3;
    vector<int> cnt(4);
    for (int i=1; i<=n; i++){
        cin >> a >> b >> g;
        swap(shell[a], shell[b]);
        cnt[shell[g]] ++;
    }
    int m = max(max(cnt[1], cnt[2]), cnt[3]);
    cout << m;
    return 0;

}