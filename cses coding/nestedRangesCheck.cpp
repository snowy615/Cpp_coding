#include <bits/stdc++.h>
using namespace std;

struct Range {
    int x;
    int y;
    int index;
};

//sort x ascending, if equal, sort y descending.
bool compare(const Range& a, const Range& b){
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    for (int i=0; i<n; i++){
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end(), compare);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    int cur_max_y = 0;
    for (int i = 0; i<n; i++){
        if (ranges[i].y <= cur_max_y) contained[ranges[i].index] = 1;
        cur_max_y = max(cur_max_y, ranges[i].y);
    }

    int cur_min_y = 2e9;
    for (int i=n-1; i>=0; i--){
        if (ranges[i].y >= cur_min_y) contains[ranges[i].index] = 1;
        cur_min_y = min(cur_min_y, ranges[i].y);
    }

    for (int i = 0; i<n; i++) cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i<n; i++) cout << contained[i] << " ";
    cout << "\n";
    return 0;
}