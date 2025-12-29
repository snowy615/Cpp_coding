#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

//greedy assign large number into sets.
int main(){
    ll n;
    cin >> n;
    ll tSum = n*(n+1)/2;
    if (tSum % 2 != 0) cout << "NO\n";
    else{
        cout << "YES\n";
        ll t = tSum/2;
        vector<int> set1, set2;
        for (int i=n; i>=1; i--){
            if (i <= t){
                set1.push_back(i);
                t -= i;
            } else{
                set2.push_back(i);
            }
        }
        cout << set1.size() << "\n";
        for (int s: set1) cout << s << " ";
        cout << "\n";
        cout << set2.size() << "\n";
        for (int s: set2) cout << s << " ";
    }
}