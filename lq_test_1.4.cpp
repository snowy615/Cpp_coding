#include <iostream>
using namespace std;
int arr[1010];

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (i > 0 && arr[i-1]%10 != int(arr[i]/10)) cnt ++;

    }
    cout << cnt;
}