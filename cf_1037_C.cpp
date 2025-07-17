#include <iostream>
using namespace std;
#include <set>

int main(){
    set <int> s;
    int t;
    int v;
    int n, k;
    int cur;
    int wl;
    int mmax;
    cin >> t;
    for (int i=0; i<t; i++){
        s.clear();
        cin >> n >> k;
        wl = 1;
        mmax = 0;

        for (int j=1; j<=n; j++) {
            cin>>v;
            s.insert(v);
            if (j==k) cur = v;
            mmax = max(v, mmax);
        }
        //cout << cur << "\n";
        bool top = true;
        for (int x: s){
            //cout << "x " << x << " cur " << cur << " wl " << wl << "\n";
            if (cur == mmax) break;
            if (x > cur){
                wl += x-cur;
                if (wl-1 == cur) {
                    cur = x;
                    continue;
                }
                if (wl-1 > cur) {
                    top = false;
                    break;
                }
                cur = x;
            }
        }
        if (top == 0) cout << "No\n";
        else cout << "Yes\n";
    }
}