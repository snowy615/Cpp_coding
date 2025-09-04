#include <iostream>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y){
    if (b==0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

int getabs(int x) {
    return x<0?-x:x;
}

signed main(){
    int t;
    cin >> t;
    while (t--){
        int a, b, m;
        cin >> a >> b >> m;
        int x, y;
        int d = exgcd(getabs(a), getabs(m), x, y);
        if (b%d) cout << -1 << "\n";
        else {
            x *= (a<0?-1:1)*(b/d);
            x = (x % (m/d) + m/d)%(m/d);
            cout << x << "\n";
        }

    }
}