#include <iostream>
#include <bitset>
#include <vector>
#define int long long
using namespace std;

const int N = 1e6+5;
bitset<N> v;
int pre[N];

void euler(int n){
    vector<int> p;
    v[0] = true;
    v[1] = true;
    for (int i=2; i<=n; i++){
        if (!v[i]) p.push_back(i);
        for (int j=0; j<p.size() && i*p[j] <= n; j++){
            v[i*p[j]] = true;
            if (i%p[j] == 0) break;
        }
    }
}

signed main(){
    int n, q;
    cin >> n >> q;
    euler(n);
    for (int i=1; i<=n; i++) pre[i] = pre[i-1] + (int) (!v[i] && !v[i/2]);
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << pre[r]-pre[l-1] << "\n";
    }
    return 0;
}
