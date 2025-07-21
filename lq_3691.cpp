#include <iostream>
using namespace std;

int n, q;
int l, r, cnt;
const int N = 1e5+1;
int a[N], p[32][N];


int main(){
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int w=0; w<=30; w++){
        for (int j=1; j<=n; j++){
            p[w][j] = p[w][j-1] + ((a[j] >> w) &1);
        }
    }
    for (int i=1; i<=q; i++){
        cin >> l >> r;
        cnt = 0;
        for (int w=0; w<=30; w++) cnt += (1 << w) * (p[w][r]-p[w][l-1]?1:0);
        cout << cnt << "\n";
    }
    return 0;

}