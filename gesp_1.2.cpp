#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    while (b){
        gcd(max(a-b, b), min(a-b, b));
    }
    return a;
}
int main(){
    int m, n;
    cin >> m >> n;

}