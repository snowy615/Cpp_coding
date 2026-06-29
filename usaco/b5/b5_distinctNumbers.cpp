#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i<n; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());
    auto last_unique = unique(numbers.begin(), numbers.end());
    int distinct_cnt = last_unique-numbers.begin();
    cout << distinct_cnt << "\n";
    return 0;
}