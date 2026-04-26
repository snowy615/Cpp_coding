#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i=0; i<m; i++){
        string s;
        cin >> s;
        for (int kk=0; kk<k; kk++){
            for (int j=0; j<n; j++){
                for (int kkk=0; kkk<k; kkk++) cout << s[j];
            }
            cout << "\n";
        }
    }
}