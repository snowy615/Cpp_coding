#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e5+5;
int n, k, T;
int s[N];
int sc[N];


//var = E(x^2) - [E(x)]^2
bool check(int mid){
    for (int i=1; i<=mid; i++) sc[i] = s[i];
    ll first[mid+1], second[mid+1];
    sort(sc+1, sc+mid+1);
    for (int i=1; i<=n; i++){
        first[i] = first[i-1]+s[i];
        second[i] = second[i-1]+s[i]*s[i];
    }
    for (int i=0; i<=mid-k; i++){
        if ((second[i+k]-second[i])*k*k-(first[i+k]*first[i+k]-first[i]*first[i]) <= T*k*k) return true;
    }
    return false;
}

int main(){
    cin >> n >> k >> T;
    for (int i=1; i<=n; i++) cin >> s[i];
    int l = 1, r = n;


    while (l < r){
        int mid = (l+r) >> 1;
//        cout << l << " " << r << "\n";
        if (check(mid)) r = mid;
        else l = mid+1;
    }
//    cout << "\n\n" << l << " " << r << "\n";
    if (check(l)) cout << l;
    else cout << -1;
}