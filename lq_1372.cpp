#include <iostream>
using namespace std;
const int N = 1e5+10;
int arr[N];
int main(){
    int n, s;
    cin >> n >> s;
    int cnt = n+1;
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int r=0, l=1, sum=0; l<=n; l++){
        while (l>r || (r+1 <= n && sum<s)) sum += arr[++ r];

        if (sum >= s) {
            cnt = min(cnt, r-l+1);
            sum -= arr[l];
        }
    }
    if (cnt > n) cout << 0;
    else cout << cnt;
    return 0;
}