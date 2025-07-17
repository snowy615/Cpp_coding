#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
const int N=1e5+10;
int p[N];
int s[N];
int mmin;
int main(){
    int t;
    cin >> t;
    int n;
    for (int i=0; i<t; i++){
        cin >> n;

        for (int j=0; j<n; j++) cin >> p[j];
        for (int j=0; j<n; j++) cin >> s[j];
        mmin = gcd(p[0], s[0]);
        bool tt=1;
        for (int j=1; j<n; j++){
            if (gcd(p[j], s[j])!=mmin){
                tt=0;
                break;
            }
        }
        if (tt==0) cout << "no\n";
        else cout << "yes\n";

    }
}