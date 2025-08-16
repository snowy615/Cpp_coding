
//int nCr(int r){
//    double sum = 1;
//    // Calculate the value of n choose r using the binomial coefficient formula
//    for (int i = 1; i <= r; i++){
//        sum = sum * (n - r + i) / i;
//    }
//    int s = (int)sum;
//    return s%2;
//}

#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int num[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    n--;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        // Use Lucas theorem: C(n, i) mod 2 == 1 iff (i & n) == i
        if ( (i & n) == i ) {
            ans ^= num[i];
        }
    }
    cout << ans;
}
