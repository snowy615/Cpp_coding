#include <iostream>
using namespace std;
const int N = 1e4+5;
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        for (int j=1; j<=i/2; j++){
            int c = a[j]+a[i-j];
            if (c>a[i]) a[i] = c;
        }
    }
    cout << a[n];

}