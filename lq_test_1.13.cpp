#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a2, a3, a4, b4, b6, s;
    for (int i=1; i<=n; i++){
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        s = 0;
        //3+3
        int v = min(a3/2, b6);
        a3 -= v*2, b6 -= v, s+=6*v;
        //4
        v = min(a4, b4);
        a4 -= v, b4 -= v, s+=4*v;
        //2+2+2
        v = min(b6, a2/3);
        a2 -= v*3, b6 -= v, s += v*6;
        //2+2
        v = min(b4, a2/2);
        a2 -= v*2, b6 -= v, s += v*4;
        //2+4
        v=min(min(a4, a2),b6);
        a2 -= v, a4 -= v, b6 -= v, s += v*6;

        //last cases
        //2+3
        v=min(min(a4, a2),b6);
        a2 -= v, a3 -= v, b6 -= v, s += v*5;

        int b = b4+b6;
        v = min(b, a3), a3 -= v, b -= v, s+=v*3;
        v = min(b, a2), a2 -= v, b -= v, s+=v*2;


        cout << s << "\n";
    }
}