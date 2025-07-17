#include <iostream>
using namespace std;
int n, a, b, x, y;
int main() {
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a >> b >> x >> y;
        int d = b-a;
        if (d < -1) cout << -1 << "\n";
        else if (d == -1 && (a^1) == b) cout << y << "\n";
        else if (d == -1) cout << -1 << "\n";
        else if (d == 0) cout << 0 << "\n";
        else{
            if (y>=x) cout << x*d << "\n";
            else{
                if (d%2 == 0) cout << d/2*(x+y) << "\n";
                else{
                    if ((a^1) == a+1) cout << int(d/2)*(x+y) + y << "\n";
                    else cout << int(d/2)*(x+y) + x << "\n";
                }
            }
        }
    }
}
