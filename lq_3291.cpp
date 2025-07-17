#include <iostream>
using namespace std;

int main(){
    int n, m;
    int x,y,z;
    while (cin >> n>> m){
        int lis[100010], dif[100010];
        lis[0] = 0;
        dif[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> lis[i];
            dif[i] = lis[i]-lis[i-1];
        }
        for (int i = 1; i <= m; i++){
            cin >> x >> y >> z;
            dif[x] += z;
            dif[y+1] -= z;

        }
        for (int i = 1; i <= n; i++){
            dif[i] += dif[i-1];
            cout << dif[i] << " ";

        }
        cout << "\n";
    }

}

