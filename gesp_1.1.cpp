#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k, t;
    cin >> n >> k >> t;
    cout << min(n, k*t);
    return 0;
}