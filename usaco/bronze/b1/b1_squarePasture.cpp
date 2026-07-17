#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2>> by2;
    int ml, mr, mu, md;
    ml = min(ax1, bx1);
    mr = max(ax2, bx2);
    mu = max(ay2, by2);
    md = min(ay1, by1);
    cout << pow(max(mr-ml, mu-md),2);
    return 0;
}