#include <iostream>
using namespace std;
int n;
const int N = 1e5+5;
int num[N];
int nCr(int r){
    double sum = 1;
    // Calculate the value of n choose r using the binomial coefficient formula
    for (int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    int s = (int)sum;
    return s%2;
}

int main(){
    cin >> n;
    n --;
    int ans = 0;
    for (int i=0; i<=n; i++){
        cin >> num[i];
        if (nCr(i)) ans = ans ^ num[i];
    }
    cout << ans;
}

