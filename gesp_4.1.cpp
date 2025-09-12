#include <iostream>
using namespace std;
const int N = 1e2+5;
char cc[N][N];
int main(){
    int r, c;
    int r1, r2, c1, c2;
    cin >> r >> c;
    cin >> r1 >> r2 >> c1 >> c2;
    bool t;

    for (int i=1; i<=r; i++){
        t = 0;
        for (int j=1; j<=c; j++){
            cin >> cc[i][j];
            if (i>=r1 && i<=r2 && j >= c1 && j<=c2){
                cout << cc[i][j];
                t = 1;
            }
        }
        if (t) cout << "\n";
    }
    return 0;
}