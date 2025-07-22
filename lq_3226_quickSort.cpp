#include <iostream>
using namespace std;
const int N = 1e5+5;
int n;
int a[N];

int p(int l, int r){
    //partition
    int pivot = a[r], pl=l, pr=r;
    while (pl < pr){
        while (pl<pr && a[pl] <= pivot) pl ++;
        while (pl<pr && a[pr] >= pivot) pr --;
        if (pl < pr) swap(a[pl], a[pr]);
        else swap(a[pl], a[r]);
    }
    return pl;
}
void qs(int l, int r){
    if (l>=r) return;
    int mid = p(l, r);
    qs(l, mid-1);
    qs(mid+1, r);
}


int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    qs(1, n);
    for (int i=1; i<=n; i++) cout << a[i] << " ";

}