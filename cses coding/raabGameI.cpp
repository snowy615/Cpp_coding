#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, a, b;
    cin >> t;
    while (t--){
        cin >> n >> a >> b;
        if (a+b > n) cout << "NO\n";
        else{
            vector<int> a(n), b(n);
            vector<int> fa(n), fb(n);
            for (int i=1; i<=n; i++){
                a[i] = i;
                b[i] = i;
            }
            for (int i=n; i>=n-a-b+1; i--){
                fa.push_back(a[i]);
                fb.push_back(b[i]);
                // a[i].erase(a.begin()) not efficient
                a.pop_back();
                b.pop_back();
            }
            for (int i=0; i<a; i++){
                fa.push_back(a[0]);
                fb.push_back(b[b.size()-1]);
                a.erase(a.begin());
                b.pop_back();
            }
            for (int i=0; i<b; i++){
                fb.push_back(b[0]);
                fa.push_back(a[a.size()-1]);
                b.erase(b.begin());
                a.pop_back();
            }
            cout << "YES\n";
            for (int i=0; i<fa.size(); i++) cout << fa[i] << " ";
            cout << "\n";
            for (int i=0; i<fb.size(); i++) cout << fb[i] << " ";
            cout << "\n";
            
        }
    }
}