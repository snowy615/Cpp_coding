#include <bits/stdc++.h>
using namespace std;

struct Drink {
    int p, m, t;
};

struct Sick {
    int p, t;
};

int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, D, S;
    cin >> N >> M >> D >> S;

    vector<Drink> drinks(D);
    for (int i = 0; i < D; i++){
        cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
    }

    vector<Sick> sicks(S);
    for (int i = 0; i<S; i++){
        cin >> sicks[i].p >> sicks[i].t;
    }

    int max_doses = 0;
    for (int milk = 1; milk <= M; milk++){
        bool pbad = true;
        for (const auto& sick: sicks){
            bool drank_before = false;
            for (const auto& drink: drinks){
                if (drink.p == sick.p && drink.m == milk && drink.t < sick.t){
                    drank_before = true;
                    break;
                }
            }
            if (!drank_before){
                pbad = false;
                break;
            }
        }
        if (pbad){
            set<int> victims;
            for (const auto& drink: drinks){
                if (drink.m == milk) victims.insert(drink.p);
            }
            max_doses = max(max_doses, (int)victims.size());
        }
    }
    cout << max_doses;
    return 0;

}