#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int n, m;
    string s;
    while (t--){
        bool yes = false;
        set<int> sets;
        cin >> n >> m;
        getline(cin, s);
        vector<int> v(m, 0);
        for (int i = 1; i<=n; i++){
            getline(cin, s);
            stringstream ss(s);
            int idx;
            while (ss >> idx){
                sets.insert(idx);
            }
            for (int e: sets){
                v[e-1] ++;
                if (v[e-1] > 2) yes = true;
            }
            for (int i=0; i<m; i++) cout << v[i] << " ";
            cout << "\n";
        }

        if (any_of(v.begin(), v.end(), [](int x){return x==0;})) cout << "No\n";
        else{
            if (yes) cout << "Yes\n";
            else if (count(v.begin(), v.end(), 2)>=2) cout << "Yes\n";
            else cout << "No\n";
        }

    }
}