#include <iostream>
using namespace std;
const int N = 105;
int cnt[N];

//void cc(){
//    for (int i=1; i<N; i++) cout << cnt[i] << " ";
//    cout << "\n";
//};
int main(){
    int t, n;
    cin >> t;
    while (t--){
        for (int i=1; i<N; i++) cnt[i] = 0;
        cin >> n;
        int a, b, res = 1;
        if (n==0) {
            cout << 0 << "\n";
            continue;
        }else if (n==1) {
            cin >> a;
            cout << 1 << "\n";
        }else if(n==2){
            cin >> a >> b;
            cout << 2 << "\n";
        }
        else{
            cin >> a;
            for (int i=2; i<=n; i++){
                cin >> b;
                if(i==n){
                    if (b==a) {
                        res ++;
                    }
                    else {
                        cnt[1] ++;
                    }
                    cnt[res] ++;
                }else if (b!=a){
                    cnt[res] ++;
                    a=b;
                    res = 1;
                }else {
                    res ++;
                }

            }
            for (int i=101; i>0; i--){
                cnt[i] += cnt[i+1];
            }
            int ans = 1;
            for (int i=1; i<N; i++){
                if (i*cnt[i] > ans) ans=i*cnt[i];
            }
            cout << ans << '\n';
        }


    }
}