#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int cnt[100010];
    cnt[0] = 0;
    cin >> s;
    int ml = 0;
    for (int i = 1; i<=s.size(); i++){
        if (s[i-1] == 'L') cnt[i] = cnt[i-1]-1;
        else cnt[i] = cnt[i-1]+1;
    }
    //cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " "<< cnt[3] << " "<< cnt[4] << "\n";
    for (int i = 1; i<=s.size(); i++){
        for (int j = i; j<=s.size(); j++){
//            if (cnt[j] == 0) ml = max(ml, j);
            if (cnt[j] - cnt[i-1] == 0) {
                //cout << i << " " << j;
                ml = max(j-i+1, ml);
            }
        }
    }
    cout << ml;
}