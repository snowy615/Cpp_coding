#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int v;

int decToQ(int n){
    string s = "";
    while (n>0) {
        int b = n%4;
        if (b>=2) return -1;
        s.push_back('0' + b);
        n /= 4;
    }
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main(){
    int cnt=0;

    for (int i=1; i<=2024; i++){
        v = decToQ(i);
        if (v>0) cnt ++;
    }
    cout << cnt;
}