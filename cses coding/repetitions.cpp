#include <iostream>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    char c = s[0];
    int cnt=0, mcnt=0;
    for (int i=0; i<=s.length(); i++){
        if (s[i]==c) cnt ++;
        else {
            mcnt = max(cnt, mcnt);
            cnt = 1;
            c = s[i];
        }
    }
    cout << mcnt;
}