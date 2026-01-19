#include <iostream>
#include <cmath>
using namespace std;

void solveHanoi(int n, int source, int target, int auxiliary){
    if (n==0) return;

    solveHanoi(n-1, source, auxiliary, target);

    cout << source << " " << target << "\n";

    solveHanoi(n-1, auxiliary, target, source);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << (1<<n) - 1 << "\n";
    solveHanoi(n, 1, 3, 2);


    return 0;
}