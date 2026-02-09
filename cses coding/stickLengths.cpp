#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <ll> p(n);
    for (int i=0; i<n; i++) cin >> p[i];
    // get median do not need full sort
    nth_element(p.begin(), p.begin()+n/2, p.end()); // nth_element(first, nth, last)= left, pivot, right
    ll median = p[n/2];

    ll total_cost = 0;
    for (int i = 0; i<n; i++) total_cost += abs(p[i]-median);
    cout << total_cost;
    return 0;
}