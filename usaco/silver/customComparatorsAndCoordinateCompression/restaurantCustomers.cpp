#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll, ll>> events;
    for (int i=0; i<n; i++){
        ll start, end;
        cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }
    sort(events.begin(), events.end());

    ll current_customers = 0;
    ll max_customers = 0;

    for (auto event: events) {
        current_customers += event.second;
        max_customers = max(max_customers, current_customers);
    }
    cout << max_customers << "\n";
    return 0;
}