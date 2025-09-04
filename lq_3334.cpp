#include <iostream>
using namespace std;

int f(int x){
    int res = 0;
    while (x) res += x%10, x/=10;
    return res;
}

bool isPrime(int x){
    if (x < 2) return false;
    for (int i=2; i<=x/i; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (isPrime(f(i))) ans ++;
    }
    cout << ans;
    return 0;
}