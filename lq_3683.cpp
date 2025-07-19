#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e2 +5; // should be 1e9+10;
int n, m;
int t[N];
int mid;


int check(){
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

#include <iostream>
#include <algorithm> // Required for std::sort

using namespace std;

// FIX 1: Set N to a reasonable limit for the number of elements, n.
// 100005 is a common size for competitive programming problems.
const int N = 100005;
int n, m;
int t[N];
int mid;

// The check function is correct, assuming the array is sorted.
int check() {
    int cnt = 0;
    // We can always place the first one.
    // lst stores the position of the last chosen element.
    int lst = 0;
    for (int i = 1; i <= n; i++) {
        // If lst is 0 (first element) or the distance is large enough
        if (lst == 0 || t[i] - t[lst] >= mid) {
            cnt++;
            lst = i;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    // FIX 2: Sort the array before performing the binary search.
    sort(t + 1, t + n + 1);

    // Using mid in the condition `t[i] - t[lst] >= mid` requires this binary search structure.
    int l = 0, r = 1e9 + 5;
    int ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2; // Avoids overflow vs. (l+r)/2
        if (check() >= m) {
            ans = mid; // This mid is a possible answer, try for a larger one
            l = mid + 1;
        } else {
            r = mid - 1; // This mid is too large
        }
    }
    cout << ans;
    return 0;
}