#include <iostream>
#include <numeric>
using namespace std;

int main(){
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        cout << gcd(a,b) << "\n";
    }
}