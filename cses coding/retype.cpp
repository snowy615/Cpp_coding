#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

void solveHanoi(int total, int source, int target, int auxiliary){
    if (total==0) return;
    solveHanoi(total-1, source, auxiliary, target);
    cout << source << " " << target << "\n";
    solveHanoi(total-1, auxiliary, target, source);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cout << (1<<n) - 1 << "\n";
    solveHanoi(n, 1, 3, 2);
    return 0;

}