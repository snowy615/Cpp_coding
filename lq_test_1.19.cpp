#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5+5;
int n, k, T;
ll s[N];
ll first[N], second[N];

//var = E(x^2) - [E(x)]^2
bool check(int mid){
    for (int i=mid; i<=n; i++){
        if (second[i]-first[i-mid-1]*first[i-mid-1]-second[i-mid-1]+first[i] < T) return true;
    }
    return false;
}

int main(){
    cin >> n >> k >> T;
    for (int i=1; i<=n; i++) cin >> s[i];
    sort(s+1, s+n+1);
    int l = 0, r = n+1;

    for (int i=1; i<=n; i++){
        first[i] = first[i-1]+s[i];
        second[i] = second[i-1]+s[i]*s[i];
    }
    while (l+1 < r){
        int mid = (l+r) >> 1;
        cout << l << " " << r << "\n";
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (l==0) cout << -1;
    else cout << l;
}