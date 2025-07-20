#include <iostream>
using namespace std;

int main(){
    unsigned int n;
    int cnt = 0;
    cin >> n;
    while(n){
        if(n&1) cnt ++;
        n >>= 1;
    }
    cout << cnt;
    return 0;
}