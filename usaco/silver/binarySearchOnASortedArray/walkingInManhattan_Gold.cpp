#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//use binary lifting (1 double jump, 2 dj, 4 dj, etc.)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> V, H;
    for (int i = 0; i < n; i++) {
        char type;
        ll c;
        cin >> type >> c;
        if (type == 'H') H.push_back(c);
        else V.push_back(c);
    }

    sort(H.begin(), H.end());
    sort(V.begin(), V.end());

    int N_h = H.size();
    int N_v = V.size();

    vector<int> first_even_H(N_h + 1, N_h), first_odd_H(N_h + 1, N_h); //index of the first even/odd horizontal road at or after index i
    for (int i = N_h - 1; i >= 0; i--) {
        first_even_H[i] = (H[i] % 2 == 0) ? i : first_even_H[i+1]; // mark if even, otherwise carry answer from i+1
        first_odd_H[i] = (H[i] % 2 != 0) ? i : first_odd_H[i+1];
    }

    vector<int> first_even_V(N_v+1, N_v), first_odd_V(N_v+1, N_v);
    for (int i = N_v - 1; i >= 0; i--) {
        first_even_V[i] = (V[i] % 2 == 0) ? i : first_even_V[i+1];
        first_odd_V[i] = (V[i] % 2 != 0) ? i : first_odd_V[i+1];

    }
    //up = index of road cow will land on after making 2^k jumps
    vector<vector<int>> up_V(19, vector<int>(N_v+1, N_v));
    vector<vector<int>> up_H(19, vector<int>(N_h+1, N_h));

    //parity rule = if on even road, next bounce on same axis will be on next odd road
    for (int i = 0; i < N_v; i++) {
        up_V[0][i] = (V[i] % 2 == 0) ? first_odd_V[i+1] : first_even_V[i+1];
    }
    for (int j = 0; j < N_h; j++) {
        up_H[0][j] = (H[j] % 2 == 0) ? first_odd_H[j+1] : first_even_H[j+1];
    }

    for (int k = 1; k < 19; k++) {
        for (int i = 0; i < N_v; i++) {
            if (up_V[k-1][i] != N_v) up_V[k][i] = up_V[k-1][up_V[k-1][i]];

        }
        for (int j = 0; j < N_h; j++) {
            if (up_H[k-1][j] != N_h) up_H[k][j] = up_H[k-1][up_H[k-1][j]];
        }
    }

    for (int i = 0; i < q; i++) {
        ll x, y, d;
        cin >> x >> y >> d;
        ll P = (x+y)%2;

        bool on_v = binary_search(V.begin(), V.end(), x);
        bool on_h = binary_search(H.begin(), H.end(), y);

        int dir; // 0=North, 1=East
        if (on_v) dir = 0; //on intersection or on vert
        else dir = 1;

        int v_idx = N_v, h_idx = N_h;
        while (d > 0) {
            //find first turn manually
            if (dir == 0) {
                int target_H_parity = (1+P+(x%2)) % 2;
                int idx = upper_bound(H.begin(), H.end(), y) - H.begin();
                int target_idx = (target_H_parity == 0) ? first_even_H[idx] : first_odd_H[idx];

                if (target_idx == N_h) break;

                ll dist = H[target_idx] - y;
                if (d >= dist) {
                    d -= dist;
                    y = H[target_idx];
                    dir = 1;
                    v_idx = lower_bound(V.begin(), V.end(), x) - V.begin();
                    h_idx = target_idx;
                    break;

                }else break;
            }else {
                int target_V_parity = (P + (y%2))%2;
                int idx = upper_bound(V.begin(), V.end(), x) - V.begin();
                int target_idx = (target_V_parity == 0) ? first_even_V[idx] : first_odd_V[idx];
                if (target_idx == N_v) break;

                ll dist = V[target_idx] - x;
                if (d >= dist) {
                    d -= dist;
                    x = V[target_idx];
                    dir = 0;
                    v_idx = target_idx;
                    h_idx = lower_bound(H.begin(), H.end(), y) - H.begin();
                    break;
                } else break;
            }
        }
        //cow on intersection, so binary lifting
        if (d > 0 && v_idx != N_v && h_idx != N_h) {
            for (int k = 18; k >= 0; k--) {
                if (up_V[k][v_idx] != N_v && up_H[k][h_idx] != N_h) {
                    ll req_dist = (V[up_V[k][v_idx]] - V[v_idx]) + (H[up_H[k][h_idx]] - H[h_idx]);

                    if (d >= req_dist) {
                        d -= req_dist;
                        v_idx = up_V[k][v_idx];
                        h_idx = up_H[k][h_idx];
                        x = V[v_idx];
                        y = H[h_idx];

                    }
                }
            }
        }
        if (dir == 0) {
            int nh = up_H[0][h_idx];
            if (nh != N_h && d >= H[nh] - y) {
                d -= (H[nh] - y);
                y = H[nh];
                dir = 1;
            }
        } else {
            int nv = up_V[0][v_idx];
            if (nv != N_v && d >= V[nv] - x) {
                d -= (V[nv] - x);
                x = V[nv];
                dir = 0;

            }
        }
        if (dir == 0) y += d;
        else x += d;

        cout << x << " " << y << "\n";
    }
    return 0;
}