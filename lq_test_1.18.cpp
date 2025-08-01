#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
const int N=3e5+5;
int n,m, a, b;
int dif[N], pre[N];
vector<pair<int,int>> v;
int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        v.push_back({a,b});
        dif[a] ++;
        dif[b+1] --;
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        dif[i] += dif[i-1];
        pre[i] += pre[i-1]+(dif[i]<=1);
        if (dif[i] == 0) ans ++;
    }
    for(int i=0; i<m; i++) cout << pre[v[i].second]-pre[v[i].first-1]+ans << endl;
    return 0;
}
