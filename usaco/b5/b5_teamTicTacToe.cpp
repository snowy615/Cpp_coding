#include <bits/stdc++.h>
using namespace std;


set<char> single_winners;
set<pair<char, char>> team_winners;

void check_line(char c1, char c2, char c3) {
    set<char> uc; //uc = unique chars
    uc.insert(c1);
    uc.insert(c2);
    uc.insert(c3);
    if (uc.size() == 1) single_winners.insert(*uc.begin());
    else if (uc.size() == 2) {
        auto it = uc.begin();
        char cow1 = *it;
        it ++;
        char cow2 = *it;
        team_winners.insert({cow1, cow2});
    }
}
int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    vector<string> board(3);
    for (int i = 0; i<3; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < 3; i++) {
        check_line(board[i][0], board[i][1], board[i][2]);
    }

    for (int j = 0; j < 3; j++) {
        check_line(board[0][j], board[1][j], board[2][j]);
    }

    check_line(board[0][0], board[1][1], board[2][2]);
    check_line(board[0][2], board[1][1], board[2][0]);

    cout << single_winners.size() << "\n";
    cout << team_winners.size() << "\n";

    return 0;

}