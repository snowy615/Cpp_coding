#include <iostream>
using namespace std;

const int N=2e5+5;
int ps[N];
int shift[N];

int main(){
    string s;
    int n, q;
    int l, r, k;
    cin >> n >> q;
    cin >> s;
    for (int i=1; i<=q; i++){
        cin >> l >> r >> k;
        k = k%26;
        ps[l] += k;
        ps[r+1] -= k;
    }
//    for (int i=1; i<=n; i++) cout << ps[i] << " ";
//    cout << "\n";
    for (int i=1; i<=n; i++) shift[i] = shift[i-1]+ps[i];

    for (int i=1; i<=n; i++){
        //cout << "\n "<< s[i-1] << "\n";
        char c = 'a'+ (s[i-1] -'a'+ shift[i])%26;
        cout << c;
    }
}