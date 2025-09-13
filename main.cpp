#include <iostream>
using namespace std;
const int N = 1e4;
int p[N];
int cnt=1;
int main(){
    for (int i=2; i<=1e9; i++){
        bool t = 0;
        for (int j=1; j<cnt; j++){
            if (i%p[j] == 0) t = 1;
        }
        if (t ==0) {
            p[cnt] = i;
            cnt ++;
        }
    }
    for (int i=1; i<=N; i++){
        cout << p[i] << ", ";
    }
}