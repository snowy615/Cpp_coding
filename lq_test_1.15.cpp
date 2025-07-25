#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int chocoDate[100010];
struct T{
    ll p, d, q;
};

bool comparePDQ(const T &a, const T &b) {
    if (a.p != b.p) return a.p < b.p;
    if (a.d != b.d) return a.d < b.d;
    return a.q < b.q;
}

vector<T> v;
ll x, n;

int main(){
    cin >> x;
    cin >> n;
    ll p, d, q;
    for (int i=1; i<=n; i++){
        cin >> p >> d >> q;
        v.push_back({p, d, q});
    }
    sort(v.begin(), v.end(), comparePDQ);
    ll q_c = 0, p_c = 0;
    for (auto vv: v){
        if (q_c == x) break;
        ll mq = min(min(vv.q, vv.d), x-q_c);
        ll qq = 0;
        for (int l=vv.d; l>=1; l--){
            if(!chocoDate[l]) {
                chocoDate[l] = 1;
                qq ++;
            }
            if (qq == mq) break;
        }
        p_c += qq*vv.p;
        q_c += qq;
    }
    if (q_c == x) cout << p_c;
    else cout << "-1";
    return 0;

}