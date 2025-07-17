#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int arr[N];

int main(){
    int w, n;
    cin >> w;
    cin >> n;
    for (int i=1;i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+n+1);
    int l = 1, r = n, cnt = 0;
    while (l <= r){
        if (l==r){
            cnt ++;
            break;
        }else if(arr[r] + arr[l] <= w){
            l ++;
            r --;
            cnt ++;
        }else{
            r--;
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}