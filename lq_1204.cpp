#include <iostream>
using namespace std;
const int N = 2e6+5;
int nex[N][26];
int idx = 2;

bool check(char s[]){
    int x = 1;
    for (int i=0; s[i]; i++) x = nex[x][s[i]-'a'];
    return x != 0;
}

void insert(char s[]){
    int x = 1;
    for (int i=0; s[i]; i++){
        if(!nex[x][s[i]-'a']) nex[x][s[i]-'a'] = idx ++;
        x = nex[x][s[i]-'a'];
    }

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        char s[N];
        cin >> s;
        insert(s);
    }
    for (int i=1; i<=m; i++){
        char s[N];
        cin >> s;
        cout << (check(s) ? "Y":"N") << "\n";

    }
    return 0;
}