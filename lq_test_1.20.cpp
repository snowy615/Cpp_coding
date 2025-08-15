#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
const int N=1e3+5;

int n;
int pre[N], a[N];
vector <int> v;
signed main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        pre[i] = pre[i-1]+a[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            v.push_back(pre[j]-pre[i-1]);
        }
    }
    sort(v.begin(), v.end());
    int md=1e9+5;
    for (int i=1; i<n; i++){
        int d= abs(v[i]-v[i-1]);
        if (d<md) md = d;
    }
    cout << md;
}
