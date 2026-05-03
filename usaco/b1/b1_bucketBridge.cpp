#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int bx, by, lx, ly, rx, ry;
    char c;
    for (int x=0; x<10; x++){
        for (int y=0; y<10; y++){
            cin >> c;
            if (c == 'B'){
                bx = x;
                by = y;
            } else if (c == 'L'){
                lx = x;
                ly = y;
            } else if (c == 'R'){
                rx = x;
                ry = y;
            }
        }
    }
    if (bx == lx && rx == bx && (by < ry && ry < ly || ly < ry && ry < by)) cout << abs(by-ly)+1;
    else if (by == ly && ry == by && (bx < rx && rx < lx || lx < rx && rx < bx)) cout << abs(bx-lx)+1;
    else cout << abs(bx-lx)+abs(by-ly)-1;
    return 0;
}