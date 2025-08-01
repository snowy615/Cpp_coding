#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const int N=3e5+5;
int n,m, a, b;
int dif[N];
ll pre[N];
vector<pair<int,int>> v;
int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        v.push_back({a,b});
        dif[a] ++;
        dif[b+1] --;
    }
    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1]+dif[i];
    }
    for(int i=0; i<v.size(); i++){
        ll cnt = 0;
        for (int j=1; j<=n; j++){
            int cur = pre[j];
            if (v[i].first <= j && j <= v[i].second) cur --;
            if (cur == 0) cnt ++;
        }
        cout << cnt << "\n";
    }
}
