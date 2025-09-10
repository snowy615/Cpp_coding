#include <iostream>
using namespace std;
const int N = 1e6+5;
int v[N];
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (i*j%2 == 0) cnt ++;
        }
    }
    cout << cnt;
    return 0;

}

