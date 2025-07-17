#include <iostream>
#include <algorithm>
using namespace std;

int const N = 1e6+10;
char arr[N];

int main(){
    int n, x;
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    if (arr[1]==arr[n]){
        for (int i=1; i<=n/x; i++) cout << arr[1];
        if (n%x != 0) cout << arr[1];
    } else if (arr[x] == arr[1]){
        for (int i =x; i <=n; i++) cout << arr[i];
    }else {
        cout << arr[x];
    }
}

