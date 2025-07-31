#include <iostream>
using namespace std;
char b[110];

int main(){
    int n, top = 0;
    cin >> n;
    char v;
    for (int i=1; i<=n; i++){
        cin >> v;
        if (v==')' && top > 0 && b[top] == '(') top --;
        else {
            top ++;
            b[top] = v;
        }
    }
    if (top) cout << "No";
    else cout << "Yes";

}