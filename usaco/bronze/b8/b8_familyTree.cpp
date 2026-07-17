#include <bits/stdc++.h>
using namespace std;
//lca = lowest common ancestor, d1, d2.
//no lca, not related
//d1, d2, =
//1,1 = cow 1 is sibling of cow2
//0, (1,2,3...) cow1 is the mother, grandmother,... of cow2
//(1,2,...), 0, cow2 is a direct ancestor of cow1
//>1, 1, cow2 is the aunt, great aunt, ...of cow1
//1, >1 aunt
//>1, >1 cousins

map<string, string> mother; //key=child, value=mother
vector<string> get_lineage(string cow) {
    vector<string> lineage;
    string cur = cow;
    while (cur != "") {
        lineage.push_back(cur);
        if (mother.count(cur)) cur = mother[cur];
        else break;
    }
    return lineage;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int n;
    string cow1, cow2;
    cin >> n >> cow1 >> cow2;

    for (int i = 0; i < n; i++) {
        string m, c;
        cin >> m >> c;
        mother[c] = m;
    }

    vector<string> path1 = get_lineage(cow1);
    vector<string> path2 = get_lineage(cow2);

    int dist1 = -1, dist2 = -1;
    string lca = "";

    //lca
    for (int i = 0; i < path1.size(); i++) {
        for (int j = 0; j < path2.size(); j++) {
            if (path1[i] == path2[j]) {
                dist1 = i;
                dist2 = j;
                lca = path1[i];
                break;
            }
        }
        if (lca != "") break;
    }

    if (lca == "") cout << "NOT RELATED";
    else if (dist1 == 1 && dist2 == 1) cout << "SIBLINGS";
    else if (dist1 == 0 && dist2 > 0) {
        cout << cow1 << " is the ";
        for (int i = 0; i < dist2-2; i++) cout << "great-";
        if (dist2 > 1) cout << "grand-";
        cout << "mother of " << cow2;
    }else if (dist1 > 0 && dist2 == 0) {
        cout << cow2 << " is the ";
        for (int i = 0; i < dist1-2; i++) cout << "great-";
        if (dist1 > 1) cout << "grand-";
        cout << "mother of " << cow1;
    }else if (dist1 > 1 && dist2 == 1) {
        cout << cow2 << " is the ";
        for (int i = 0; i < dist1 - 2; i++) cout << "great-";
        cout << "aunt of " << cow1;
    } else if (dist2 > 1 && dist1 == 1) {
        cout << cow1 << " is the ";
        for (int i = 0; i < dist2 - 2; i++) cout << "great-";
        cout << "aunt of " << cow2;
    } else {
        cout << "COUSINS";
    }
    return 0;
}