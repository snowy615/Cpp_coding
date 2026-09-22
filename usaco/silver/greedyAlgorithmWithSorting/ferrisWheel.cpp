#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int l = 0, r = n-1, cnt = 0;
    while (l <= r){
        if (p[l] + p[r] <= x) {
            l ++;
            r --;
        }
        else r --;
        cnt ++;
    }
    cout << cnt;
    return 0;
}