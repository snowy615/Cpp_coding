#include <iostream>
#include <bitset>
#include <vector>
#define int long long
using namespace std;

const int N = 1e5+5;
bitset<N> v;
vector<int> p;
int x, y;

void euler(int n){
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
    int q;
    cin >> q;
    int n=1e5;
    euler(n);



    while (q--){
        int px=0, py=0, cx = 0, cy=0;
        cin >> x >> y;
        while (x!=y){
            if (x>y) {
                if (x%p[px]==0) {
                    cx++;
                    x /= p[px];
                }
                else px ++;
            }else {
                if (y%p[py]==0) {
                    cy++;
                    y /= p[py];
                }
                else py ++;
            }
        }
    cout << cx + cy << "\n";
    }
}