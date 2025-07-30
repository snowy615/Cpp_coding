#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+5;
int c[N];
int main(){
    int n, q, k, m;
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> c[i];
    int *c_max = max_element(c+1, c+n+1);
    int *c_min = min_element(c+1, c+n+1);

    for (int i=1; i<=q; i++){
        cin >> k >> m;
        //*c_max>k &&
        if (*c_max-k>*c_min-k) cout << m*(2k-*c)
    }
}
