#include <iostream>
using namespace std;
#include <queue>
#include <vector>
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>> mpq;

int main(){
    int n;
    cin >> n;
    ll cnt = 0LL;
    for (int i=1; i<=n; i++){
        ll e;
        cin >> e;
        mpq.push(e);
    }
    while (mpq.size() > 1){
        ll t1 = mpq.top();
        mpq.pop();
        ll t2 = mpq.top();
        mpq.pop();
        cnt += t1 + t2;
        mpq.push(t1+t2);
    }
    cout << cnt;
    return 0;


}