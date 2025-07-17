#include <iostream>
using namespace std;

int main(){
    int n, num, m;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num;
        m = 10;
        while (true) {
            m = min(num%10, m);
            num /= 10;
            if (num == 0) break;
        }
        cout << m << "\n";
    }
}