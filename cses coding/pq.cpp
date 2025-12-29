#include <iostream>
#include <queue>
#include <functional>
using namespace std;
using ll = long long;

priority_queue<ll,vector<ll>,greater<ll>>pq;

signed main(){
    ll n, x;
    ll s = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> x;
        pq.push(x);
    }
    while (pq.size()>1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        pq.push(a+b);
        s += a+b;
    }
    cout << s;
    return 0;
}

//.push().pop().top().empty().size()
//3
//1
//2
//9