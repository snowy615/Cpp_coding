#include <iostream>
#include <queue>
using namespace std;

using ll = long long;
priority_queue<ll> pq;
int n, q;
ll x;

int main(){
    ll sum = 0;
    int m;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sum += x;
        pq.push(x);
    }
    for (int i=1; i<=q; i++){
        cin >> m;
        while (pq.top()>=m){
            x = pq.top();
            pq.pop();
            sum -= x;
            sum += x%m;
            pq.push(x%m);
        }
        cout << sum << " ";
    }
    return 0;
}