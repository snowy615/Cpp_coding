#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c: s) cnt[c-'A'] ++;

    int odd_cnt = 0;
    char odd_c = 0;
    for (int i=0; i<26; i++){
        if (cnt[i]%2!=0){
            odd_cnt ++;
            odd_c = (char)(i+'A');
        }
    }
    if (odd_cnt > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    string lh="";
    for (int i = 0; i<26; i++){
        //string(n,c)=n copies of c
        lh += string(cnt[i]/2, (char)('A'+i));
    }
    string rh = lh;
    reverse(rh.begin(), rh.end());
    if (odd_cnt) cout << lh << odd_c << rh;
    else cout << lh << rh;
    return 0;

}