#include <iostream>
using namespace std;

const int N = 1e5+5;
int nums[N], dfn[N];
int n;
int mindfn=1, idx=1, ans=0;

int dfs(int person){
    int next = nums[person];
    if (dfn[next]){
        if (dfn[next] < mindfn) return 0;
        return dfn[person]-dfn[next]+1;
    }
    dfn[next] = idx ++;
    return dfs(next);
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> nums[i];
    for (int i=1; i<=n; i++){
        if (dfn[i]) continue;
        dfn[i] = idx;
        mindfn = idx++;
        ans = max(ans, dfs(i));
    }
    cout << ans;
}