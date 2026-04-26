#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rec {
    ll x1, y1, x2, y2;
    bool see(){
        return (x1 < x2 && y1 < y2);
    }
};
Rec intersect(Rec a, Rec b){
    if (b.x2 <= a.x1 || b.x1 >= a.x2 || b.y2 <= a.y1 || b.y1 >= a.y2) {
        return a;
    }
    else if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y1 <= a.y1 && b.y2 >= a.y2) {
        a.x1 = 0, a.x2 = 0, a.y1 = 0, a.y2 = 0;
    }
    else if (b.x1 <= a.x1 && b.x2 >= a.x2 && (b.y1 <= a.y1 || b.y2 >= a.y2)) {
        if (b.y1 <= a.y1) {
            a.y1 = b.y2;
        } else a.y2 = b.y1;
    }
    else if (b.y1 <= a.y1 && b.y2 >= a.y2 && (b.x1 <= a.x1 || b.x2 >= a.x2)) {
        if (b.x1 <= a.x1){
            a.x1 = b.x2;
        }else a.x2 = b.x1;
    }
    return a;
}
int main(){
    Rec a, b, c;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    a = intersect(a, b);
    a = intersect(a, c);
    if (!a.see()) cout << "NO";
    else cout << "YES";
    return 0;
}