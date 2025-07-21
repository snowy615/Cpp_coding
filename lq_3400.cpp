#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e4+5;
int n;
int a[N], p[N];

bool is_pq(int num){
    int q = sqrt(num);
    if (q*q == num) return true;
    return false;
}
int main(){
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
        p[i] = p[i-1]^a[i];
        //cout << p[i] << " ";
    }
    //cout << "\n";
    int cnt = 0;
    for (int l=1; l<=n-1; l++){
        for (int r=l; r<=n; r++){
            if (is_pq(p[r]^p[l-1])) {
                //cout << l << " " << r << "\n";
                cnt ++;
            }
        }
    }
    cout << n*(n+1)/2-cnt << "\n";
}