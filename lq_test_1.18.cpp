#include <iostream>

using namespace std;
const int N=3e5+5;
int n,m, a, b;
int dif[N];
vector<pair<int,int>> v;
int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        v.push_back({a,b});
        dif[a] ++;
        dif[b+1] --;
    }
    for(int i=0; i<v.size(); i++){
        int cnt = 0, pre=0;
        for (int j=1; j<=n; j++){
            pre += dif[j];
            if (j==v[i].first) pre --;
            if (j==v[i+1].second) pre ++;
            if (!pre) cnt ++;
        }
        cout << cnt << "\n";
    }
}