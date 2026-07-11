#include <bits/stdc++.h>
using namespace std;

//cannot have A and B, A not B, B not A simultaneously

bool has_feature(const vector<string>& p, const string& f) {
    return find(p.begin(), p.end(), f) != p.end();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<string>> p(n);//population
    vector<string> all_f;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string f;
            cin >> f;
            p[i].push_back(f);
            if (find(all_f.begin(), all_f.end(), f) == all_f.end()) all_f.push_back(f);
        }
    }

    for (int i = 0; i < all_f.size(); i++) {
        for (int j = i+1; j < all_f.size(); j++) {
            string A = all_f[i];
            string B = all_f[j];

            bool has_A_only = false;
            bool has_B_only = false;
            bool has_both = false;

            for (int pi = 0; pi < n; pi++) {
                bool has_A = has_feature(p[pi], A);
                bool has_B = has_feature(p[pi], B);

                if (has_A && !has_B) has_A_only = true;
                if (!has_A && has_B) has_B_only = true;
                if (has_A && has_B) has_both = true;
            }

            if (has_A_only && has_B_only && has_both) {
                cout << "no";
                return 0;
            }
        }
    }
    cout << "yes";
    return 0;

}