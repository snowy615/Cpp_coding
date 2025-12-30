#include <iostream>
using namespace std;

using ll = long long;
// a b remove 1 2 remove 2 1

int main(){
    ll t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if ((a+b)%3!=0 || a>2*b || b>2*a) cout << "NO\n";
        else cout << "YES\n";
    }
}