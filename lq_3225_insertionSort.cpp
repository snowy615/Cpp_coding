#include <iostream>
using namespace std;

const int N =1e4;
int a[N];
int n, v, j;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=2; i<=n; i++){
        v = a[i];
        for (j=i; a[j-1]>v; j--){
            a[j] = a[j-1];
        }
        a[j] = v;
    }
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
}