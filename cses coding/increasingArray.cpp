#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll mcur=0, x=0, s=0;
    for (int i=0; i<n; i++){
        cin >> x;
        if (i==0) mcur = x;
        if (x < mcur) s += mcur-x;
        mcur = max(mcur, x);
    }
    cout << s;
    return 0;
}