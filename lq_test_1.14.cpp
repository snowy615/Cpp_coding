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
    //reverse(a+1, a+ma+1);
    cin >> mb;
    for (int i=1; i<=mb; i++) cin >> b[i];
    //reverse(b+1, b+mb+1);
    int total_digit = max(ma, mb);
    for (int i=1; i<=total_digit; i++){
        int s = a[i]-b[i]-bd;
        int base = max(max(a[i]+1, b[i]+1), s);

        if (s>=0){
            cnt += pow(base,i-1)*s;
            cout << "0 _ i " << i << " s " << s << " cnt " << pow(base,i-1)*s << "\n";
            bd = 0;
        }else{
            cnt += pow(base, i-1)*(s+base);
            cout << "0 _ i " << i << " s " << s << " cnt " << pow(base, i-1)*(s+base)<< "\n";
            bd = 1;
        }
    }
    cout << cnt;
    return 0;

}