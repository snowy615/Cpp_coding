//sliding window right add new songs, if duplicate, then move left until duplicate song is removed

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i=0; i<n; i++) cin >> songs[i];
    //song id, value
    map<int, int> last_seen;
    int left = 0;
    int max_len = 0;

    for (int right = 0; right < n; right++){
        int current_song = songs[right];
        if (last_seen.count(current_song)) left = max(left, last_seen[current_song]+1);
        last_seen[current_song] = right;
        max_len = max(max_len, right-left+1);
    }
    cout << max_len;
    return 0;
}

