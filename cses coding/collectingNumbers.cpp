#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        pos[val] = i;
    }
    //index of order
    int rounds = 1;
    for (int i = 1; i<n; i++){
        if (pos[i+1] < pos[i]) rounds++; //in front
    }
    cout << rounds;
    return 0;
}