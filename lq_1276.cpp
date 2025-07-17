#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll arr[N];
ll dif[N];

int main(){
    int n, q;
    int l, r, x;

    cin >> n >> q;
    arr[0] = 0;
    dif[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        dif[i] = arr[i]-arr[i-1];
        //cout << dif[i] << " ";
    }
    //cout << "\n";

    for (int i = 1; i<=q; i++){
        cin >> l >> r >> x;
        dif[l] += x;
        dif[r+1] -= x;
        //for (int j=1;j<=n; j++) cout << dif[j] << " ";
        //cout << "\n";
    }

    for (int i = 1; i<=n; i++){
        dif[i] += dif[i-1];
        cout << max(dif[i], 0LL) << ' ';
    }
}