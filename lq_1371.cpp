#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6+10;
char arr[N];
int main(){
    cin >> arr+1;
    int n = strlen(arr+1);
    int l = 1, r=n;
    bool t = true;
    while (l<r && t){
        if (arr[l] != arr[r]) t = false;
        l++, r--;
    }
    if (t) cout << "Y";
    else cout << "N";
    return 0;
}