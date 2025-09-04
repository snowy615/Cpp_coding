#include <iostream>
#include <vector>
#include <bitset>
#define int long long
using namespace std;
const int N = 1e5+5;

bitset<N> v;
vector<int> p;

void init(int n){
    v[0] = true;
    v[1] = true;
    for (int i=2; i<=n; i++){
        if (!v[i]) for (int j=2*i; j<=n; j+=i) v[j] = true;
    }
    for (int i=1; i<=n; i++) if (!v[i]) p.push_back(i);
}

signed main(){
    int n;
    cin >> n;
    init(n);
    int cnt = 0;
    for (int i=0; i<p.size(); i++){
        for (int j=0; j<i; j++){
            if (!v[p[i]-p[j]]) cnt ++;
        }
    }
    cout << cnt;
    return 0;
}