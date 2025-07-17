#include <iostream>
using namespace std;
const int N = 1e6;
int arr[N];

int main(){
    int n;
    int cnt = 0;
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    for (int i = 2; i<n; i++){
        if (arr[i] >= arr[i-1] + arr[i+1]) cnt ++;
    }
    cout << cnt;

}