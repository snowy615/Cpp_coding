#include <iostream>
using namespace std;

int check(int num){
    int res = 0;
    while (num){
        res += num%2;
        num >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    while (n--){
        int num;
        cin >> num;
        cnt += check(num);
    }
    cout << cnt << " ";
    if (cnt%2) cout << 1;
    else cout << 0;
    return 0;
}