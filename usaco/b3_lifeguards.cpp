#include <bits/stdc++.h>
using namespace std;

struct lg {
    int start;
    int end;
};

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    vector<lg> guards(n);
    for (int i = 0; i < n; i++){
        cin >> guards[i].start >> guards[i].end;
    }
    int max_t = 0;

    for (int i = 0; i<n; i++){
        bool t_covered[1000] = {false};
        for (int j = 0; j<n; j++){
            if (i == j) continue; //skip fired lifeguard
            for (int t = guards[j].start; t < guards[j].end; t++) t_covered[t] = true;
        }
        int cur_covered_t = 0;
        for (int t = 0; t<1000; t++){
            if (t_covered[t]) cur_covered_t ++;
        }
        max_t = max(max_t, cur_covered_t);
    }
    cout << max_t;
    return 0;

}