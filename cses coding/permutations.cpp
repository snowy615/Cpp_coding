#include <iostream>
using namespace std;

using ll = long long;

int main(){
    ll n, ind;
    cin >> n;
    if (n==2 || n==3) cout << "NO SOLUTION";
    else{
        if (n%2==0) ind = 1;
        else ind = 0;
        for (ll i = 1; i<(n+1)/2+ind; i++){
            cout << i*2 << " ";
        }
        for (ll i = 0; i<(n+1)/2; i++){
            cout << i*2+1 << " ";
        }

    }
}