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
    all.resize(n);
    for (int i=0; i<n; i++){
        cin >> all[i].first >> all[i].second;
    }
    sort(all.begin(), all.end(), greater<pair<int, int>>());
    int snd_max = all[0].second;
    int cnt = 1;
    for (int i=1; i<n; i++){
        if (snd_max <= all[i].second || all[i].first == all[0].first) {
//            cout << i << " " << all[i].first << " " << all[i].second << '\n';
//            cout << snd_max << "\n\n";
            cnt ++;
            snd_max = max(all[i].second, snd_max);
        }
    }
//    cout << "\n\n\n";
    cout << cnt;
}