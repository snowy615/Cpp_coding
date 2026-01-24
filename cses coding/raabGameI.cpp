#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    if (a+b > n) {
        cout << "NO\n";
        return;
    }
    if (a+b>0 && (a==0 || b==0)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<int> p1, p2;
    int ties = n-a-b;
    for (int i=1; i<=ties; i++){
        p1.push_back(i);
        p2.push_back(i);
    }
    vector<int> rem_cards;
    for (int i=ties+1; i<=n; i++){
        rem_cards.push_back(i);
    }
    
    p1.insert(p1.end(), rem_cards.begin(), rem_cards.end());
    vector<int> p2_rem = rem_cards;
    if (!rem_cards.empty()){
        rotate(p2_rem.begin(), p2_rem.begin()+a, p2_rem.end());

    }
    p2.insert(p2.end(), p2_rem.begin(), p2_rem.end());

    for (int i=0; i<n; i++) cout << p1[i] << (i==n-1 ? "\n" : " ");
    cout << "\n";
    for (int i=0; i<n; i++) cout << p2[i] << (i==n-1 ? "\n" : " ");
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
