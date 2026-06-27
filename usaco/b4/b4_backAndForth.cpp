#include <bits/stdc++.h>
using namespace std;

set<int> possible_readings;

void dfs(int day, int milk1, vector<int> b1, vector<int> b2) {
    if (day == 4) {
        possible_readings.insert(milk1);
        return;
    }


    if (day%2 == 0) {
        for (int i = 0; i<b1.size(); i++) {
            vector<int> next_b1 = b1;
            vector<int> next_b2 = b2;
            int bucket = b1[i];
            next_b1.erase(next_b1.begin()+i);
            next_b2.push_back(bucket);
            dfs(day+1, milk1-bucket, next_b1, next_b2);
        }
    }else {
        for (int i = 0; i < b2.size(); i++) {
            vector<int> next_b1 = b1;
            vector<int> next_b2 = b2;
            int bucket = b2[i];
            next_b2.erase(next_b2.begin()+i);
            next_b1.push_back(bucket);
            dfs(day+1, milk1+bucket, next_b1, next_b2);
        }
    }
}
int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> b1(10), b2(10);
    for (int i = 0; i<10; i++) cin >> b1[i];
    for (int i = 0; i<10; i++) cin >> b2[i];
    dfs(0, 1000, b1, b2);
    cout << possible_readings.size() << "\n";
    return 0;
}