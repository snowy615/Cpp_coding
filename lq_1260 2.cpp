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

//or
//int gcd(int a, int b){
//    return b == 0 ? a : gcd(b, a%b);
//}