#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> board(8);
vector<bool> d1(15, false), d2(15, false);
vector<bool> col(8, false);
int solution = 0;

void search(int row){
    if (row == 8) {
        solution++;
        return;
    }

    for (int c = 0; c<8; c++){
        if (col[c] || d1[c+row] || d2[c-row+7] || board[row][c]=='*') continue;
        col[c] = d1[c+row] = d2[c-row+7] = true;
        search(row+1);
        col[c] = d1[c+row] = d2[c-row+7] = false;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0; i<8; i++) cin >> board[i];
    search(0);
    cout << solution << "\n";


}