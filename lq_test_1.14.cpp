#include <iostream>
using namespace std;
int n;
const int N=1e5+5;
int ma, mb;
int a[N], b[N];

int main(){
    int cnt = 0;
    cin >> n;
    cin >> ma;
    for (int i=1; i<=ma; i++) cin >> a[i];
    reverse(a+1, a+ma+1);
    cin >> mb;
    for (int i=1; i<=mb; i++) cin >> b[i];
    reverse(b+1, b+mb+1);

    for (int i=1; i<=max(ma, mb); i++){
        int m =
    }

}