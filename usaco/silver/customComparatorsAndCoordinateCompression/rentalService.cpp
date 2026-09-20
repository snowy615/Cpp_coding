#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct store {
    ll qty;
    ll price;
};

bool compareStores(const store& a, const store& b) {
    return a.price > b.price;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;

    vector<ll> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.rbegin(), cows.rend());//descending

    vector<store> stores(m);
    for (int i = 0; i < m; i++) {
        cin >> stores[i].qty >> stores[i].price;
    }

    sort(stores.begin(), stores.end(), compareStores);

    vector<ll> rentals(r);
    for (int i = 0; i < r; i++) {
        cin >> rentals[i];
    }
    sort(rentals.rbegin(), rentals.rend());

    vector<ll> rent_prefix(r+1, 0);
    for (int i = 1; i <= r; i++) {
        rent_prefix[i] = rent_prefix[i-1] + rentals[i-1];
    }

    vector<ll> milk_profit(n+1, 0);
    int store_idx = 0;

    for (int i = 1; i <= n; i++) {
        ll cur_profit = milk_profit[i-1];
        ll gallons = cows[i-1];
        while (gallons > 0 && store_idx < m) {
            ll take = min(gallons, stores[store_idx].qty);
            cur_profit += take*stores[store_idx].price;
            gallons -= take;
            stores[store_idx].qty -= take;

            if (stores[store_idx].qty == 0) store_idx ++;
        }
        milk_profit[i] = cur_profit;
    }

    ll max_profit = 0;
    for (int i = 0; i <= n; i++) {
        int cows_to_rent = n-i;
        int rented = min(cows_to_rent, r);
        ll cur_total = milk_profit[i] + rent_prefix[rented];
        max_profit = max(max_profit, cur_total);
    }

    cout << max_profit;
    return 0;

}