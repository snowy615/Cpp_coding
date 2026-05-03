#include <bits/stdc++.h>
using namespace std;

int get_v(char c){
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    if (c == 'T') return 3;
    return 0;
}
int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> spot(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m ; j++){
            spot[i][j] = get_v(s[j]);
        }
    }
    vector<vector<int>> plain(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            plain[i][j] = get_v(s[j]);
        }
    }

    int valid_sets = 0;

    for (int p1 = 0; p1 < m; p1++){
        for (int p2 = p1+1; p2 < m; p2++){
            for (int p3 = p2+1; p3 < m; p3++) {
                bool spot_has[64] = {false};
                for (int i = 0; i < n; i++){
                    int id = (spot[i][p1]*16) + (spot[i][p2]*4) + spot[i][p3];
                    spot_has[id] = true;
                }
                bool overlap = false;

                for (int i = 0; i < n; i++){
                    int id = (plain[i][p1]*16) + (plain[i][p2]*4) + plain[i][p3];
                    if (spot_has[id]){
                        overlap = true;
                        break;
                    }
                }
                if (!overlap) valid_sets++;
            }
        }
    }
    cout << valid_sets;
    return 0;

}