#include <iostream>
#include <vector>
using namespace std;
const int N=1e5+5;
int n;
int iv[N];
vector<int> v[N];

bool dfs(int depth, int cnt){
    if(depth == n+1) return true;
    for (int i=1; i<=cnt; i++){
        bool tag = true;
        for (const auto &j:v[i]) if(iv[depth] % j ==0){
            tag = false;
            break;
        }
        if (!tag) continue;
        v[i].push_back(iv[depth]);
        if (dfs(depth+1, cnt)) return true;
        v[i].pop_back();
    }
    return false;

}


int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> iv[i];
    sort(iv+1, iv+n+1);
    for (int i=1; i<=10; i++) {
        if(dfs(1,i)) {
            cout << i;
            return 0;
        }
    }
}