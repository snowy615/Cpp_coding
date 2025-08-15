#include <iostream>
#include <cmath>

#define int long long
using namespace std;
const int N=1e3+5;

int n;
int pre[N];

signed main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    int md=pre[n];
    for (int i=1; i<=n; i++){
        int d= abs(pre[n]-2*pre[i]);
        if (d<md) md = d;
    }
    cout << md;
}
