#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> yes;
vector<pair<int, int>> all;

int main(){
    int n;
    cin >> n;
    int a, b;
    for (int i=1; i<=n; i++){
        cin >> a >> b;
        all.push_back({a,b});
    }
    sort(all.begin(), all.end(), greater<pair<int, int>>());
    yes.push_back(all[0]);
    //cout << yes.size() << " y " << all.size() << "\n";
    //for (int i=0; i<n; i++) cout << all[i].first << " " << all[i].second << "\n";
    for (int i=1; i<n; i++){
        bool f = true;
        for (int j=0; j<yes.size(); j++){
            if (yes[j].first > all[i].first && yes[j].second>all[i].second){
                f = false;
                break;
            }
        }
        if (f) {
             //cout << i << "i\n";
            yes.push_back(all[i]);
        }
    }
    cout << yes.size();
}