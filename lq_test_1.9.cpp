#include <iostream>
using namespace std;
string s;
using ll = long long;
int k;
const int N = 5e6;
char st, en;
int p[N];
int main(){
    cin >> k;
    cin >> s;
    cin >> st >> en;
    int n = s.size();
    //cout << n << " n \n";
    ll cnt = 0;
    //cout << st << " " << en;
    for (int i=0; i<n; i++){
        p[i+k-1] = p[i+k-2];
        if (s[i] == st){
            //cout << "in at " << i << " \n";
            p[i+k-1] ++;
            //cout << p[i+k-1] << " add \n";
        }
        if (s[i] == en){
            cnt += p[i];
        }
        //cout << p[i] << " p[i] ";
    }
    //cout << "\n\n";
    cout << cnt;
}