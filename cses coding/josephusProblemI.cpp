#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    for (int i=1; i<=n; i++) q.push(i);
    bool skip = true;
    while (!q.empty()){
        int current = q.front();
        q.pop();
        if (skip) q.push(current);
        else cout << current << " ";
        skip = !skip;
    }
    cout << "\n";
    return 0;

}