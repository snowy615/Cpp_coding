#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int a, b, c;
    int ma, mb, mc;
    cin >> ma >> a;
    cin >> mb >> b;
    cin >> mc >> c;
    int p;

    for (int i = 1; i<=33; i++){
        p = min(a, mb-b);
        a -= p;
        b += p;
        p = min(b, mc-c);
        b -= p;
        c += p;
        p = min(c, ma-a);
        c-= p;
        a += p;
    }
    p = min(a, mb-b);
    a -= p;
    b += p;
    cout << a << "\n" << b << "\n" << c;
}