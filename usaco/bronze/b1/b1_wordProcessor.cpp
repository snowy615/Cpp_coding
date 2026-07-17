#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int cur_len = 0;
    string word;
    for (int i = 0; i<n; i++){
        cin >> word;
        if (cur_len + word.length() <= k){
            if (cur_len > 0) cout << " ";
            cout << word;
            cur_len += word.length();
        }else {
            cout << "\n" << word;
            cur_len = word.length();
        }
    }
    cout << "\n";
    return 0;
}