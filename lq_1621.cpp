#include <iostream>
using namespace std;
const int N = 2e6+10;
int arr[N];

int main(){
    int n, m, k;
    int sum = 0;
    cin >> n >> m >> k;
    for (int i = 1; i<=n; i++ ){
        cin >> arr[i];
    }
    for (int l=1, r=0, cnt = 0; l<=n; l++) {
        while (l > r || (r + 1 <= n && cnt < k)) cnt += (arr[++r] >= m);
        if (cnt >= k) sum += n - r + 1;
        cnt -= (arr[l] >= m);
    }
    cout << sum;
}
