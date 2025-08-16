#include <iostream>
#include <queue>
using namespace std;
int n, v;
priority_queue<int> max_pq;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> v;
        max_pq.push(v);
    }
    while (max_pq.size()>1){
        int v1 = max_pq.top();
        max_pq.pop();
        int v2 = max_pq.top();
        max_pq.pop();
        max_pq.push(v1^v2);
    }
    cout << max_pq.top();
}