#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;

    string res = "";
    int t_len = t.length();

    for (int i = 0; i<s.length(); i++){
        res += s[i];
        if (res.length() >= t_len){
            if (res.compare(res.length()-t_len, t_len, t) == 0) res.resize(res.length()-t_len);
        }
    }
    //res.compare(start_idx, length, target_str)

    cout << res;
    return 0;
}