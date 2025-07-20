//last test case n = n+1 out of range. Solved problem using min()
#include <iostream>
using namespace std;
int s[200005];
string a;
int res;

int main(){
    int n, m;
    s[0] = 0;
    cin >> n;
    cin >> a;
    for (int i = 1; i<=n; i++){
        s[i] = s[i-1];
        if (i < n && stoi(a.substr(i-1, 1)) == 1 && stoi(a.substr(i, 1))==0) s[i] ++;
//        cout << s[i] << " ";
    }
//    cout << "\n";
    cin >> m;
    int l, r;
    for (int i = 1; i<=m; i++){
        cin >> l >> r;
        res = s[min(r, n)] - s[l-1];
        //if (r<n) cout << stoi(a.substr(r-1, 1)) << " " << stoi(a.substr(r, 1)) << "\n";
        if (r<n && stoi(a.substr(r-1, 1)) == 1 && stoi(a.substr(r, 1)) == 0) {
//            cout << "in";
            res --;
        }
        cout << res << "\n";
    }
}