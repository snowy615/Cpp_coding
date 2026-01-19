#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<string> perm;

    do {
        perm.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << perm.size() << "\n";

    for (const string& p:perm) cout << p << "\n";

    return 0;
}