#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;

    string type[100];
    int low[100], high[100];

    for (int i = 0; i < n; i++){
        cin >> type[i] >> low[i] >> high[i];
    }
    int l = -99999, h = 99999;

    for (int i = n-1; i >= 0; i--){
        if (type[i] == "none"){
            l = max(l, low[i]);
            h = min(h, high[i]);
        } else if (type[i] == "off") {
            l += low[i];
            h += high[i];
        } else {
            l -= high[i];
            h -= low[i];
            l = max(0, l);
        }
    }
    cout << l << " " << h << "\n";

    l = -99999, h = 99999;

    for (int i = 0; i < n; i++){
        if (type[i] == "none"){
            l = max(l, low[i]);
            h = min(h, high[i]);
        } else if (type[i] == "on") {
            l += low[i];
            h += high[i];
        } else {
            l -= high[i];
            h -= low[i];
            l = max(0, l);
        }
    }
    cout << l << " " << h << "\n";
    return 0;

}