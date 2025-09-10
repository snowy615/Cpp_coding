#include <iostream>
#define int long long
using namespace std;

signed main(){
    int n;
    int cur=0;
    int m=0;
    int cnt = 0;
    cin >> n;
    while (n--){
        cin >> cur;
        if (cur > m) m = cur;
        else m ++;
        cnt += m;
//        cout << cnt << "\n";
    }
    cout << cnt;
}