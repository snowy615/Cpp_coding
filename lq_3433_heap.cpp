#include <iostream>
#include <utility>

using namespace std;
using ll = long long;
const int N = 1e5+5;
ll pq[N*4];
int n, q;
ll x;
int sz = 0;

void push_up(int x){
    while (x>1 && pq[x] > pq[x/2]){
        swap(pq[x/2], pq[x]);
        x /= 2;
    }
}

void push_down(int x){
    while(x*2 <= sz) {
        int child = x*2;
        if (child +1 <= sz && pq[child+1] > pq[child]) child ++;
        if (pq[x] >= pq[child]) break;
        swap(pq[x], pq[child]);
        x = child;
    }
}

ll top(){
    return pq[1];
}

void pop(){
    pq[1] = pq[sz--];
    push_down(1);
}

void push(int x){
    pq[++sz] = x;
    push_up(sz);
}

int main(){
    ll sum = 0;
    int m;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sum += x;
        push(x);
    }
    for (int i=1; i<=q; i++){
        cin >> m;
        while (top()>=m){
            x = top();
            pop();
            sum -= x;
            sum += x%m;
            push(x%m);
        }
        cout << sum << " ";
    }
    return 0;
}