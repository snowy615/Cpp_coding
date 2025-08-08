#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5+5;
int prefix[N];
int n;

void dfs(int depth, int st, int mul, int sum){
    if (mul > 1e5) return;
    if (depth == n+1){
        prefix[mul] ++;
        return;
    }
    int up = pow(1e5/mul, 1.0/(n+1-depth))+5;
    for (int i = st+1; i<(depth==n?min(sum, up):up); i++){
        dfs(depth+1, i, mul*i, sum+i);
    }

}

int main(){
    int q, l, r;
    cin >> q >> n;
    dfs(1, 0, 1, 0);
    for (int i=1; i<N; i++) prefix[i] += prefix[i-1];

    while(q--){
        cin >> l >> r;
        cout << prefix[r]-prefix[l-1] << "\n";
    }
    return 0;

}