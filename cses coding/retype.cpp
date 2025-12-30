#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int t = 1 << n;
    for (int i = 0; i<t; i++){
        int gray_val = i^(i+1);
        for (int k=n-1; k>=0; k--)
    }

}