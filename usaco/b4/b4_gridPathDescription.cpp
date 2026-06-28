#include <bits/stdc++.h>
using namespace std;

bool visited[9][9];
int p[48];
int total_path = 0;

void solve(int r, int c, int step) {
    if (r == 7 && c == 1) {
        if (step == 48) total_path++; //yes hit
        return; //got early so no
    }
    if (step == 48) return;//didn't arrive

    if (visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1]) return;
    if (visited[r][c-1] && visited[r][c+1] && !visited[r-1][c] && !visited[r+1][c]) return;

    visited[r][c] = true;
    int nxt = p[step];
    if (nxt == 4) {//?
        if (!visited[r-1][c]) solve(r-1, c, step+1);
        if (!visited[r+1][c]) solve(r+1, c, step+1);
        if (!visited[r][c-1]) solve(r, c-1, step+1);
        if (!visited[r][c+1]) solve(r, c+1, step+1);
    } else {
        if (nxt == 0 && !visited[r-1][c]) solve(r-1, c, step+1);
        else if (nxt == 1 && !visited[r][c+1]) solve(r, c+1, step+1);
        else if (nxt == 2 && !visited[r+1][c]) solve(r+1, c, step+1);
        else if (nxt == 3 && !visited[r][c-1]) solve (r, c-1, step+1);
    }
    visited[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    for (int i = 0; i<48; i++) {
        if (s[i] == 'U') p[i] = 0;
        else if (s[i] == 'R') p[i] = 1;
        else if (s[i] == 'D') p[i] = 2;
        else if (s[i] == 'L') p[i] = 3;
        else p[i] = 4;
    }

    for (int i = 0; i < 9; i++) {
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][0] = true;
        visited[i][8] = true;
    }
    solve(1,1,0);
    cout << total_path << "\n";
    return 0;
}