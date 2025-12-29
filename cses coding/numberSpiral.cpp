#include <iostream>
using namespace std;

using ll = long long;

int main(){
    ll t;
    ll y, x;
    cin >> t;
    while (t--){
        cin >> y >> x;
        if (y>x){
            if (y%2) cout << (y-1)*(y-1)+x << "\n";
            else cout << y*y-x+1 << "\n";
        }else{
            if(x%2) cout << x*x-y+1 << "\n";
            else cout << (x-1)*(x-1)+y << "\n";
        }
    }
}