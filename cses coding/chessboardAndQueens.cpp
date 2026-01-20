#include <iostream>
#include <vector>
#include <string>

using namespace std;

string board[8];
int solutions = 0;

bool col[8];
bool d1[15];
bool d2[15];

void search(int row){
    if (row == 8){
        solutions++;
        return;
    
    }
    for (int c = 0; c<8; c++){
        if (col[c] || d1[c+row] || d2[c-row+7] || board[row][c]=='*') continue;
    
        col[c] = true;
        d1[c+row] = true;
        d2[c-row+7] = true;
        search(row+1);
        col[c] = false;
        d1[c+row] = false;
        d2[c-row+7] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i<8; i++) cin >> board[i];
    
    search(0);
    cout << solutions << "\n";
    
    return 0;
}
