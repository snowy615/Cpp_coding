#include <iostream>
using namespace std;
int num[1010];
int m, n;
int hh=1, tt=0;

int main(){
    cin >> m >> n;
    int v, cnt=0;
    for (int i=1; i<=n; i++){
        cin >> v;
        bool t=0;
        for (int j=hh; j<=tt; j++){
            if (v==num[j]){
                t=1;
            }
        }
        if (t) continue;

        if (tt-hh+1==m) hh++;
        num[++tt] = v;
        cnt ++;
    }
    cout << cnt;
    return 0;

}
