#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> cnt(26, 0);

    for (char c: s) cnt[c-'A']++;

    int max_freq = *max_element(cnt.begin(), cnt.end());

    if (max_freq > (n+1)/2){
        cout << -1;
        return 0;
    }

    string res;
    res.reserve(n);
    int last = -1;

    for (int i=0; i<n; i++){
        int rem = n - i;
        int best_char = -1;
        int max_val = -1;

        for (int c = 0; c < 26; c++){
            if (cnt[c] > max_val){
                max_val = cnt[c];
                best_char = c;
            }
        }

        int chosen = -1;
        if (2*max_val > rem) {
            chosen = best_char;
        } else {
            for (int c = 0; c < 26; c++){
                if (cnt[c] > 0 && c != last){
                    chosen = c;
                    break;
                }
            }
        }

        res += (char) ('A' + chosen);
        cnt[chosen]--;
        last = chosen;
    }

    cout << res << endl;
    return 0;
}