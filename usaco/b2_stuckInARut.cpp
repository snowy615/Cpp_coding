#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int id;
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nn;
    cin >> nn;
    //Sort all East-moving cows by their y-coordinate (bottom to top).Sort all North-moving cows by their x-coordinate (left to right). only need to check if a cow was already stopped before it reached intersection

    vector<Cow> E_cows, N_cows;

    for (int i = 0; i<nn; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') E_cows.push_back({i, x, y});
        else N_cows.push_back({i, x, y});
    }

    sort(E_cows.begin(), E_cows.end(), [](const Cow& a, const Cow& b) {return a.y < b.y;});

    sort(N_cows.begin(), N_cows.end(), [](const Cow& a, const Cow& b) {return a.x < b.x;});

    vector<int> ans(nn, -1);

    for (const auto& e: E_cows){
        for (const auto& n: N_cows){
            if (e.x < n.x && e.y > n.y){
                int disE = n.x-e.x;
                int disN = e.y-n.y;
                if (ans[e.id] != -1 && ans[e.id] < disE) continue;
                if (ans[n.id] != -1 && ans[n.id] < disN) continue;

                if (disE<disN) ans[n.id] = disN;
                if(disN<disE) ans[e.id] = disE;

            }
        }
    }
    for (int i = 0; i<nn; i++){
        if (ans[i] == -1) cout << "Infinity\n";
        else cout << ans[i] << "\n";
    }
    return 0;

}