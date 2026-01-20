#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> results;
    do {
        results.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << results.size() << "\n";
    for (auto &r:results) cout << r << "\n";

    return 0;
}