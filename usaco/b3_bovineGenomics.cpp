#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<string> spot(n);
    for (int i = 0; i < n; i++) cin >> spot[i];

    vector<string> plain(n);
    for (int i = 0; i < n; i++) cin >> plain[i];

    int valid_positions = 0;

    for (int j = 0; j < m; j++){
        bool s_c[256] = {false};
        for (int i = 0; i < n; i++){
            s_c[spot[i][j]] = true;
        }
        bool overlap = false;
        for (int i = 0; i < n; i++){
            if (s_c[plain[i][j]]) {
                overlap = true;
                break;
            }
        }
        if (!overlap) valid_positions ++;
    }
    cout << valid_positions;
    return 0;
}