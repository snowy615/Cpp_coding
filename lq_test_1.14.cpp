#include <iostream>
#include <cmath>
#include <algorithm>
using ll = long long;
using namespace std;
ll n;
const int N=1e5+5;
ll ma, mb;
ll a[N], b[N];

int main(){
    ll cnt = 0, bd = 0;
    cin >> n;
    cin >> ma;
    for (int i=1; i<=ma; i++) cin >> a[i];
    reverse(a+1, a+ma+1);
    cin >> mb;
    for (int i=1; i<=mb; i++) cin >> b[i];
    reverse(b+1, b+mb+1);
    ll total_digit = max(ma, mb);
    ll tbase = 1;
    ll v = 2;
    for (int i=1; i<=total_digit; i++){
        ll s = a[i]-b[i]-bd;
        ll base = max(max(a[i]+1, b[i]+1), max(s+1, v));

        if (s>=0){
            cnt += tbase*s;
            cnt %=1000000007;
            //cout << "0 _ i " << i << " s " << s << " cnt " << tbase*s << " tbase " << tbase << "\n";
            bd = 0;
        }else{
            cnt += tbase*(s+base);
            cnt %=1000000007;
            //cout << "0 _ i " << i << " s " << s << " cnt " << tbase*(s+base) << " tbase " << tbase << "\n";
            bd = 1;
        }
        tbase *= base;
        tbase %= 1000000007;
    }
    cout << cnt % 1000000007;
    return 0;

}