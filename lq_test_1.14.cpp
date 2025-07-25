#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
const int N=1e5+5;
int ma, mb;
int a[N], b[N];

int main(){
    int cnt = 0, bd = 0;
    cin >> n;
    cin >> ma;
    for (int i=1; i<=ma; i++) cin >> a[i];
    reverse(a+1, a+ma+1);
    cin >> mb;
    for (int i=1; i<=mb; i++) cin >> b[i];
    reverse(b+1, b+mb+1);
    int total_digit = max(ma, mb);
    int tbase = 1;
    for (int i=1; i<=total_digit; i++){
        int s = a[i]-b[i]-bd;
        int base = max(max(max(a[i]+1, b[i]+1), s+1), 2);

        if (s>=0){
            cnt += tbase*s;
            //cout << "0 _ i " << i << " s " << s << " cnt " << tbase*s << " tbase " << tbase << "\n";
            bd = 0;
        }else{
            cnt += tbase*(s+base);
            //cout << "0 _ i " << i << " s " << s << " cnt " << tbase*(s+base) << " tbase " << tbase << "\n";
            bd = 1;
        }
        tbase *= base;
    }
    cout << cnt;
    return 0;

}