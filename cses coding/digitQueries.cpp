#include <iostream>
#include <string>
using namespace std;

using ll = long long;

void solve(){
    ll k;
    cin >> k;

    ll length = 1;
    ll cnt = 9;
    ll start = 1;
    while (k > length*cnt){
        k -= length*cnt;
        length ++;
        cnt *= 10;
        start *= 10;
    }
    ll num =  start + (k-1)/length;
    string s = to_string(num);
    cout << s[(k-1)%length] << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}

