#include <iostream>
using namespace std;
using ll = long long;
const int m = 1e9+7;
int main(){
    ll n, s;
    cin >> n;
    s = 1;
    for (ll i=1; i <= n; i++){
        s = s * 2 %m;
    }
    cout << s;
}