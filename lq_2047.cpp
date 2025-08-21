#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6+5;
char s[N], p[N];
//j for p, i for s
int nex[N]; // pre=suffix

int main(){
    cin >> p+1;
    int m = strlen(p+1);
    cin >> s+1;
    int n = strlen(s+1);
    nex[0] = 0;
    nex[1] = 0;
    for (int i = 2, j = 0; i <= m; i++){
        while (j && p[i] != p[j+1]) j = nex[j];
        if (p[i] == p[j+1]) j++;
        nex[i] = j;
    }
    int res = 0;
    for (int i=1, j=0; i<=n; i++){
        while (j && p[j+1] != s[i]) j = nex[j];
        if (s[i] == p[j+1]) j++;
        if (j == m) res ++;
    }
    cout << res;

}
