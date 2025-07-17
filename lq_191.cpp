#include <iostream>
using namespace std;


bool is_num(int x){
    int y;
    while (x){
        y = x%10;
        if (y==2 || y==0 || y==1 || y==9) return true;
        x /= 10;
    }
    return false;
}


int main(){
    int n, ans=0;
    cin >> n;
    for (int i = 1; i<=n; i++){
        if (is_num(i)) ans += i;
    }
    cout << ans;
    return 0;
}
