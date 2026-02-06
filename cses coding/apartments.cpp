#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i<n; i++) cin >> applicants[i];
    for (int i = 0; i<m; i++) cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0;
    int j = 0;
    int matches = 0;

    while (i<n && j<m){
        if (apartments[j] < applicants[i]-k) j++;
        else if (apartments[j] > applicants[i]+k) i++;
        else{
            matches++;
            i++;
            j++;
        }
    }
    cout << matches << "\n";
    return 0;
}
