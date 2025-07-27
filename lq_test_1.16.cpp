#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
ll k, n, vv,tt;
const int N = 1e5+10;
ll num[N];

void update(int index, ll a){
    num[index] = a;
    if (index-1 > 0 && num[index-1] > a+1) {
        //cout << "a";
        update(index-1, a+1);
    }
    if (index+1 <= n && num[index+1] > a+1) {
        //cout << "b";
        update(index+1, a+1);
    }
}
int main(){
    cin >> k >> n;
    for (int i=1; i<=n; i++){
        num[i] = 100010;
    }
    for (int i=1; i<=k; i++){
        cin >> vv >> tt;
        update(vv, tt);
    }
    ll t_max = 0;
    for (int i=1; i<=n; i++){
        if (num[i] > t_max) t_max = num[i];
        //cout << num[i] << " ";
    }
    //cout << "\n";
    cout << t_max;
    return 0;
}