#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int price, max_price;

    multiset<int> tickets;
    for (int i=0; i<n; i++) {
        cin >> price;
        tickets.insert(price);
    }

    for (int i=0; i<m; i++){
        cin >> max_price;
        auto it = tickets.upper_bound(max_price); //first element strictly greater
        if (it == tickets.begin()) cout << -1 << "\n";
        else {
            it --;
            cout << *it << "\n";
            tickets.erase(it); // erase(iterator) = remove one, erase(value) = remove all
        }
    }
    return 0;
}