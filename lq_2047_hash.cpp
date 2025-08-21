#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6+5;
char s[N], p[N];
const ull base = 131;
ull hp[N], hs[N], b[N];

ull g_hash(ull h[], int l, int r){
    return h[r] - h[l-1]*b[r-l+1];
}
int main(){
    cin >> p+1;
    int m = strlen(p+1);
    cin >> s+1;
    int n = strlen(s+1);
    b[0] = 1;
    for (int i=1; i<=n; i++){
        b[i] = b[i-1] * base;
        hp[i] = hp[i-1] * base + p[i];
        hs[i] = hs[i-1] * base + s[i];
    }
    int res = 0;
    ull pp = g_hash(hp, 1, m);
    for (int i=1; i+m-1 <=n; i++){
        if (pp == g_hash(hs, i, i+m-1)) res ++;
    }
    cout << res;
}