#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll initial_matches = 0;
    ll destroyed = 0;

    vector<vector<ll>> posA(n+1); //distance to edge,sorted, grouped by species
    vector<vector<ll>> posB(n+1);

    for (ll i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            initial_matches++;
            destroyed += i * (n-i+1);
        }

        ll dis = min(i, n-i+1);
        posA[a[i]].push_back(dis);
        posB[b[i]].push_back(dis);
    }

    ll total_ops = n*(n+1)/2;
    ll ans = initial_matches * total_ops - destroyed;
    ll created = 0;

    for (int v = 1; v <= n; v++) {
        if (posA[v].empty() || posB[v].empty()) continue;

        sort(posA[v].begin(), posA[v].end());
        sort(posB[v].begin(), posB[v].end());

        vector<ll> prefB(posB[v].size()+1, 0);
        for (size_t i = 0; i < posB[v].size(); i++) {
            prefB[i+1] = prefB[i] + posB[v][i];
        }

        for (ll d_a: posA[v]) {
            auto it = upper_bound(posB[v].begin(), posB[v].end(), d_a);
            ll idx = distance(posB[v].begin(), it);
            created += prefB[idx];
            created += d_a * (posB[v].size()-idx);
        }
    }
    cout << ans + created;
    return 0;

}