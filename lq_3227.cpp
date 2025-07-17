#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;
int m, n;


int main()
{
    int x;
    cin >> m >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> x;
            mp[x] ++;
        }
    }


    for (auto &i : mp)
    {
        if (i.second * 2 > m*n) cout << i.first;
    }
    return 0;
}
