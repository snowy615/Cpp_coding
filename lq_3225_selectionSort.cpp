#include <iostream>
using namespace std;

int n;
const int N=1e3+5;
int a[N];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=n; i>=1; i--){
        int m = i;
        for (int j=1; j<=i; j++){
            if (a[j] > a[m]) m=j;
        }
        swap(a[m], a[i]);
    }

    for (int i=1; i<=n; i++) cout << a[i] << " ";
    return 0;
}