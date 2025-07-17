//method 1
#include <iostream>
#include <cmath>
using namespace std;

//int main(){
//    string s = "2021ABCD";
//    int ans = 0;
//    for (int i=0; i<8; i++) {
//        if(s[i] -'A' >= 0) ans += ((s[i] - 'A') +10)*pow(16,(7-i));
//        else ans += (s[i]-'0')*pow(16,(7-i));
//    }
//    cout << ans;
//}

//method 2
int main(){
    unsigned int x = 0x2021abcd;
    cout << x << "\n";
}