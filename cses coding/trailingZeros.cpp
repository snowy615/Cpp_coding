#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n, s;
    s = 0;
    cin >> n;
    while (n!=0){
        n /= 5;
        s += n;
    }
    cout << s;
}