#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n,x;
    cin >> n;
    ll s = n*(n+1)/2;
    for (int i=1; i<n; i++){
        cin >> x;
        s -= x;
    }
    cout << s;
    return 0;
}