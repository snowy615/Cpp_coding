#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> road_limits(100);
    vector<int> bessie_speeds(100);

    int cur_mile = 0;
    for (int i = 0; i<n; i++){
        int length, limit;
        cin >> length >> limit;
        for (int j = 0; j < length; j++){
            road_limits[cur_mile] = limit;
            cur_mile ++;
        }
    }
    cur_mile = 0;
    for (int i = 0; i < m; i++){
        int length, speed;
        cin >> length >> speed;
        for (int j = 0; j < length; j++){
            bessie_speeds[cur_mile] = speed;
            cur_mile ++;
        }
    }

    int max_over = 0;

    for (int i = 0; i < 100; i++){
        int over = bessie_speeds[i] - road_limits[i];
        if (over > max_over) max_over = over;
    }

    cout << max_over;
    return 0;
}