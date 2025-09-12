#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e3 + 5;
int a[N][2];
int n;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    int cnt = 0;
    if (n <= 1) cout << 0;
    else{
        for (int i=2; i<=n; i++){
            for (int j=2; j<=n; j++){
                if (a[j][0] > a[j-1][0] || a[j][0]==a[j-1][0]&&a[j][1]>a[j-1][1]){
                    swap(a[j-1], a[j]);
                    cnt ++;
                }
            }
        }
    }


    cout << cnt;



}
