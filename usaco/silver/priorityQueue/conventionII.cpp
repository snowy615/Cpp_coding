#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Cow {
    int id;
    ll a;
    ll t;
};

bool compareA(const Cow& a, const Cow& b) {
    if (a.a == b.a) return a.id < b.id;
    return a.a < b.a;
}

struct compareS {
    bool operator()(const Cow& a, const Cow& b) {
        return a.id > b.id;
    }
};
int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        cows[i].id = i;
        cin >> cows[i].a >> cows[i].t;
    }

    sort(cows.begin(), cows.end(), compareA);

    priority_queue<Cow, vector<Cow>, compareS> pq;

    int next_cow_idx = 0;
    ll cur_time = 0;
    ll max_wait = 0;

    while (next_cow_idx < N || !pq.empty()) {
        if (pq.empty() && cur_time < cows[next_cow_idx].a) {
            cur_time = cows[next_cow_idx].a;
        }

        while (next_cow_idx < N && cows[next_cow_idx].a <= cur_time) {
            pq.push(cows[next_cow_idx]);
            next_cow_idx++;
        }

        Cow cur_cow = pq.top();
        pq.pop();
        max_wait = max(max_wait, cur_time-cur_cow.a);
        cur_time += cur_cow.t;
    }

    cout << max_wait;
    return 0;
}