#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=n || dist[nx][ny]!=-1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

}