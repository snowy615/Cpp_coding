#include <bits/stdc++.h>
using namespace std;

struct Rec {
    int x1, y1, x2, y2;

    int area(){
        return (x2-x1)*(y2-y1);
    }
};
int intersect(Rec a, Rec b){
    int xOverlap = max(0, min(a.x2, b.x2)-max(a.x1, b.x1));
    int yOverlap = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
    return xOverlap*yOverlap;
}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    Rec a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    int vis_cnt = a.area()+b.area()- intersect(a, t) - intersect(b, t);
    cout << vis_cnt;
    return 0;
}