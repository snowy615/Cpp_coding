#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr(7);
    for (int i=0; i<7; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int a = arr[0];
    int b = arr[1];
    int abc = arr[6];
    cout << a << " " << b << " " << abc-a-b;
    return 0;
}