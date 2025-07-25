#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int chocoDate[100010];
struct T{
    int p, d, q;
};

bool comparePDQ(const T &a, const T &b) {
    if (a.p != b.p) return a.p < b.p;
    if (a.d != b.d) return a.d < b.d;
    return a.q < b.q;
}

vector<T> v;
int x, n;

int main(){
    cin >> x;
    cin >> n;
    int p, d, q;
    for (int i=1; i<=n; i++){
        cin >> p >> d >> q;
        v.push_back({p, d, q});
    }
    sort(v.begin(), v.end(), comparePDQ);
    int q_c = 0, p_c = 0;
    for (auto vv: v){
        if (q_c == x) break;
        int mq = min(min(vv.q, vv.d), x-q_c);
        int qq = 0;
        for (int l=1; l<=vv.d; l++){
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