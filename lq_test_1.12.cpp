#include <iostream>
using namespace std;

const int N=2e5+5;
int shift[N];

int main(){
    string s;
    int n, q;
    int l, r, k;
    cin >> n >> q;
    cin >> s;
    for (int i=1; i<=q; i++){
        cin >> l >> r >> k;
        for (int j=l; j<=r; j++) {
            shift[j] = (shift[j]+k)%26;
            //cout << j << "j "<< shift[j] << "\n";
        }
    }
    for (int i=1; i<=n; i++){
        //cout << "\n "<< s[i-1] << "\n";
        char c = 'a'+ (s[i-1] -'a'+ shift[i])%26;
        cout << c;
    }
}