#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int b1, b2, s1, s2, g1, g2, p1, p2; //tier 1/2 = before/after
    cin >> b1 >> b2;
    cin >> s1 >> s2;
    cin >> g1 >> g2;
    cin >> p1 >> p2;

    int gp = p2-p1;
    int sg = g2-g1+gp;
    int bs = s2-s1+sg;

    cout << bs << "\n";
    cout << sg << "\n";
    cout << gp << "\n";
    return 0;
}