#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    //complementary counting
    //total ways = (n^2)*(n^2-1)/2
    //attack ways (2 attacks in every 2*3 or 3*2 box) = 4*(k-1)*(k-2)
    for (ll i=1; i<=n; i++){
        cout << (i*i)*(i*i-1)/2 - 4*(i-1)*(i-2) << "\n";
    }

}