#include <iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    for (int j=0; j<n; j++){
        cin >> s;

        char c = s[0];
        int cnt = 0;
        for (int i=1; i<=3; i++){
            if (s[i] == c) cnt ++;
        }
        if (cnt == 2) cout << "Yes\n";
        else if (cnt == 0 && s[1] == s[2] && s[2]==s[3]) cout << "Yes\n";
        else cout << "No\n";
    }
}