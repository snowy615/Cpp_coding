#include <iostream>
using namespace std;
int n;
const int N=1e5+5;
int num[N];

int main(){
    cin >> n;
    int s = 0;
    for (int i=0; i<n; i++){
        cin >> num[i];
    }
    sort(num, num+n);
    for (int i=0; i<n; i++) if (i%2) s ^= num[i];
    cout << s;
}