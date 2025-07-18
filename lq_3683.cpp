#include <iostream>
using namespace std;
const int N = 1e9 +5;
int n, m;
int t[N];
int mid; // min of (max distance)


int check(){ // return max number of trees can be plotted with distance mid
    int cnt = 0;
    for (int i=1, lst=0; i<=n; i++){
        if (lst && t[i] - t[lst] < mid) continue;
        cnt ++;
        lst = i;
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> t[i];
    }
    int l=0, r=1e9+5;
    while (l+1 != r){
        mid = (l+r) >> 1;
        if (check()>=m) l=mid;
        else r=mid;
    }
    cout << l;
    return 0;
}