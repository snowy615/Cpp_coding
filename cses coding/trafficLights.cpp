#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> gaps;

    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);

    for (int i = 0; i<n; i++){
        int p;
        cin >> p;
        auto it_r = lights.upper_bound(p);
        auto it_l = it_r;
        it_l --;

        int left = *it_l;
        int right = *it_r;
        gaps.erase(gaps.find(right-left));
        gaps.insert(p-left);
        gaps.insert(right-p);
        lights.insert(p);
        cout << *gaps.rbegin() << (i == n-1 ? "": " "); // max as last element
    }
    return 0;
}
