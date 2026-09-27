#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int K, M, N;
    cin >> K >> M >> N;

    vector<pair<ll, ll>> P(K);
    for (auto& p: P) cin >> p.first >> p.second;
    sort(P.begin(), P.end());

    vector<ll> F(M+2); //Nhoj cows
    for (int i = 0; i < M; i++) cin >> F[i];
    //dummy boundary
    F[M] = -2e9;
    F[M+1] = 3e9;
    sort(F.begin(), F.end());

    vector<ll> gains;
    int p_idx = 0;

    for (int i = 0; i < M+1; i++) {
        //each segment, l = left pointer, p_idx = right pointer, sum = total grass in seg, cur = inside sliding window
        ll L = F[i], R = F[i+1], sum = 0, max_win = 0, cur = 0;
        int l = p_idx;

        while (p_idx < K && P[p_idx].first < R) {
            sum += P[p_idx].second;
            cur += P[p_idx].second;
            while ((P[p_idx].first - P[l].first) * 2 >= R-L) {
                cur -= P[l++].second;
            }
            max_win = max(max_win, cur);
            p_idx ++;
        }
        gains.push_back(max_win);
        gains.push_back(sum-max_win); //2nd cow captures rest

    }

    sort(gains.rbegin(), gains.rend());
    ll ans = 0;
    for (int i = 0; i < min(N, (int) gains.size()); i++) {
        ans += gains[i];
    }
    cout << ans;
    return 0;so le
}