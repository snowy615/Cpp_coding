#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    while (!v.empty() && q_c < x){
        if (v[0].q < x-q_c) {
            q_c += v[0].q;
            p_c += v[0].p * v[0].q;
            v.erase(v.begin());
        } else{
            p_c += v[0].q * (x-q_c);
            q_c = x;
            v.erase(v.begin());
            break;
        }
    }
    if (q_c == x) cout << p_c;
    else cout << "-1";
    return 0;

}