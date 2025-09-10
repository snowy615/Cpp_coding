#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int _gcd(int a, int b){
    if (b>a) {
        return _gcd(b, a);
    }
    if (b==0) return a;
    return _gcd(a%b, b);
}
int main(){
    int m, n;
    cin >> m >> n;
    cout << m*n/_gcd(m, n);

    return 0;
}