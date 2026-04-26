#include <bits/stdc++.h>
using namespace std;

struct Rec {
    int x1, y1, x2, y2;
};
int intersect(Rec a, Rec b){
    int area = (a.x2-a.x1)*(a.y2-a.y1);
    if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y1 <= a.y1 && b.y2 >= a.y2) return 0;
    else if (b.x1 <= a.x1 && b.x2 >= a.x2 && (b.y1 <= a.y1 || b.y2 >= a.y2)) return area-(a.x2-a.x1)*(min(a.y2, b.y2)-max(a.y1, b.y1));
    else if (b.y1 <= a.y1 && b.y2 >= a.y2 && (b.x1 <= a.x1 || b.x2 >= a.x2)) return area-(a.y2-a.y1)*(min(a.x2, b.x2)-max(a.x1, b.x1));
    else return area;

}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    Rec a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cout << intersect(a, b);
    return 0;
}