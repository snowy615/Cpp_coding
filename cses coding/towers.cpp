//greedy algo, minimize tower (add to lowest), implement using multiset (allow duplicates and sorted)

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> towers;

    for (int i=0; i<n; i++){
        int cube_size;
        cin >> cube_size;

        auto it = towers.upper_bound(cube_size);
        //if tower exists
        if (it != towers.end()) towers.erase(it);
        towers.insert(cube_size);
    }
    cout << towers.size();
    return 0;
}
//int value = *it;    get number stored at this position
