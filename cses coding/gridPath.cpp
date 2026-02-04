#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 7;
bool visited[N][N];
string path_desc;
int total_path = 0;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool in_bounds(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void solve(int r, int c, int step){
    if (r == 6 && c == 0){
        if (step == 48) total_path ++;
        return;
    }
    if (step == 48) return;

    bool can_up = in_bounds(r - 1, c) && !visited[r - 1][c];
    bool can_down = in_bounds(r + 1, c) && !visited[r + 1][c];
    bool can_left = in_bounds(r, c - 1) && !visited[r][c - 1];
    bool can_right = in_bounds(r, c + 1) && !visited[r][c + 1];

    if (!can_up && !can_down && can_left && can_right) return;
    if (!can_right && !can_left && can_up && can_down) return;
    visited[r][c] = true;

    if (path_desc[step] == '?'){
        for (int i = 0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if (in_bounds(nr, nc) && !visited[nr][nc]) solve(nr, nc, step+1);
        }
    } else {
        int dir = 0;
        if (path_desc[step] == 'U') dir = 0;
        else if (path_desc[step] == 'R') dir = 1;
        else if (path_desc[step] == 'D') dir = 2;
        else dir = 3;

        int nr = r+dr[dir];
        int nc = c+dc[dir];
        if (in_bounds(nr, nc) && !visited[nr][nc]) solve(nr, nc, step+1);
    }
    visited[r][c] = false;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> path_desc;
    visited[0][0] = true;
    solve(0, 0, 0);

    cout << total_path << endl;
    return 0;
}



