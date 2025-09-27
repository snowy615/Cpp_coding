#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> all;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a, b;
    for (int i=1; i<=n; i++){
        cin >> a >> b;
        all.push_back({a,b});
    }
    sort(all.begin(), all.end(), greater<pair<int, int>>());
    int snd_max = all[0].second;
    int cnt = 1;
    for (int i=1; i<n; i++){
        if (snd_max < all[i].second) {
            cnt ++;
            snd_max = all[i].second;
        }
    }
    cout << cnt;
}