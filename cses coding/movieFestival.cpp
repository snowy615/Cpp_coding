#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

//sort by movie end time

struct Movie {
    ll start;
    ll end;
};
//& = reference, not copy
bool compareMovies(const Movie& a, const Movie& b){
    return a.end < b.end;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Movie> movies(n);
    for (int i = 0; i<n; i++){
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end(), compareMovies);

    int cnt = 0;
    ll cur_end = -1;

    for (const auto& movie: movies) {
        if (movie.start >= cur_end){
            cnt ++;
            cur_end = movie.end;
        }
    }
    cout << cnt;
    return 0;
}

