#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> all;

int count(int x){
    int res = 0;
    while (x){
        int q = x%10;
        if (q==8) res += 2;
        if (q==0 || q==4 || q==6 || q==9) res += 1;
        x /= 10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    all.resize(n);
    int v;
    for (int i=0; i<n; i++){
        cin >> v;
        all[i].first = count(v);
        all[i].second = v;
    }
    sort(all.begin(), all.end());
    for (int i=0; i<n; i++) cout << all[i].second << " ";
}
