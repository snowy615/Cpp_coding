#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int total_people = 2*n;
    vector<int> w(total_people);

    for (int i = 0; i < total_people; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    int min_instability = INT_MAX;

    for (int i = 0; i < total_people; i++) {
        for (int j = i+1; j < total_people; j++) {
            vector<int> remaining;
            for (int k = 0; k < total_people; k++) {
                if (k != i && k != j) remaining.push_back(w[k]);
            }

            int cur_instability = 0;
            for (size_t k = 0; k < remaining.size(); k+=2) {
                cur_instability += remaining[k+1]-remaining[k];
            }
            if (cur_instability < min_instability) min_instability = cur_instability;
        }

    }
    cout << min_instability << "\n";
    return 0;
}