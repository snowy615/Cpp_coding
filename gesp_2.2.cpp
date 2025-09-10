#include <iostream>
using namespace std;

bool check(int num){
    int res = 0;
    if (num == 1) return false;
    while (num){
        res += num%2;
        num >>= 1;
        //cout << num << "\n";
    }
    if (res == 1 || res==2) return true;
    return false;
}

int main(){
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int num = l; num<=r; num++){
        if (check(num)) {
            //cout << num << "\n";
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}