#include <iostream>
#include <bitset>
#include <vector>
#define int long long
using namespace std;

const int N = 2e7+5;
bitset<N> v;
int pre[N], mp[N];

void euler(int n){
    vector<int> p;
    v[0] = true;
    v[1] = true;
    for (int i=2; i<=n; i++){
        if (!v[i]) {
            p.push_back(i);
            mp[i] = i;
        }
        for (int j=0; j<p.size() && i*p[j] <= n; j++){
            v[i*p[j]] = true;
            mp[i*p[j]] = p[j];
            if (i%p[j] == 0) break;
        }
    }
}

signed main(){
    int t;
    cin >> t;
    euler(2e7);
    for (int i=1; i<=2e7; i++) pre[i] = pre[i-1] + mp[i];
    while (t--){
        int k;
        cin >> k;
        cout << pre[k] << "\n";
    }
    return 0;
}