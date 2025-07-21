#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5+5;
ll n;
ll a[N];

int main(){
    cin >> n;
    ll cnt = 0;
    ll s = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s += a[i];
    }
   // cout << s << " s\n";
    for (int i=1; i<=n; i++){
        //cout << s*a[i] - a[i]*a[i] << " ";
        cnt += s*a[i] - a[i]*a[i];
    }
    cout << cnt/2;
}