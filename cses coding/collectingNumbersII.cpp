#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    //1-based
    vector<int> x(n+1);
    vector<int> pos(n+1);

    for (int i=1; i<=n; i++){
        cin >> x[i];
        pos[x[i]] = i;
    }
    //inital rounds
    int rounds = 1;
    for (int i = 1; i<n; i++){
        if (pos[i+1] < pos[i]) rounds++;
    }

    //process each swap operation
    for (int k = 0; k<m; k++){
        int a, b;
        cin >> a >> b;
        int va = x[a];
        int vb = x[b];
        set<int> check_vals;
        if (va > 1) check_vals.insert(va-1);
        if (va < n) check_vals.insert(va);
        if (vb > 1) check_vals.insert(vb-1);
        if (vb < n) check_vals.insert(vb);

        for (int v:check_vals){
            if (pos[v+1] < pos[v]) rounds--; // remove previous contribution
        }
        //swap
        swap(x[a], x[b]);
        pos[va] = b;
        pos[vb] = a;

        for (int v: check_vals){
            if (pos[v+1] < pos[v]) rounds ++; // add new round
        }
        cout << rounds << "\n";
    }
    return 0;

}
