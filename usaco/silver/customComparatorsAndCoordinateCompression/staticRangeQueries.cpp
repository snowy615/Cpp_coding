#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Update {
    ll l, r, v;
};

struct Query {
    ll l, r;
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<Update> updates(n);
    vector<Query> queries(q);
    vector<ll> coords;

    for (int i = 0; i < n; i++) {
        cin >> updates[i].l >> updates[i].r >> updates[i].v;
        coords.push_back(updates[i].l);
        coords.push_back(updates[i].r);
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        coords.push_back(queries[i].l);
        coords.push_back(queries[i].r);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()),coords.end());

    auto get_idx = [&](ll x) {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    int c = coords.size();
    vector<ll> diff(c+1, 0);

    for (const auto& u: updates) {
        diff[get_idx(u.l)] += u.v;
        diff[get_idx(u.r)] -= u.v;
    }

    vector<ll> pref(c+1, 0);
    ll cur_height = 0;

    for (int i = 0; i < c-1; i++) {
        cur_height += diff[i];
        ll width = coords[i+1] - coords[i];
        pref[i+1] = pref[i] + (cur_height * width);
    }

    for (const auto& q: queries) {
        int l = get_idx(q.l);
        int r = get_idx(q.r);
        cout << pref[r] - pref[l] << "\n";
    }

    return 0;
}