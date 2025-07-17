#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e5 +10;
int arr[N];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int m = arr[1]-arr[0];
    for (int i=0; i<n-1; i++) m = min(m, arr[i+1]-arr[i]);
    cout << m;
    return 0;
}