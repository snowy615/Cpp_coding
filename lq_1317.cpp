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
    int _x, _y, _m, _n, _l;
    cin >> _x >> _y >> _m >> _n >> _l;
    int a = _m-_n;
    int b = _l;
    int c = _y-_x;
    int x,y;
    int d = exgcd(getabs(a), getabs(b), x, y);

    if (c%d) cout << "impossible" << "\n";
    else {
        x *= (a<0?-1:1)*(c/d);
        x = (x % (b/d) + b/d)%(b/d);
        cout << x << "\n";
    }
}