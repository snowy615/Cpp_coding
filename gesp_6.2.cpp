#include <iostream>
using namespace std;

int prime(){

}
int count(int x){
    int cnt = 0;

}
int main(){
    int q;
    cin >> q;
    int x, y;
    while (q--){
        cin >> x >> y;
        int g = gcd(x, y);
        x /= g;
        y /= g;
    }
}