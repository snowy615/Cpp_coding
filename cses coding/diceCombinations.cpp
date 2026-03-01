#include <iostream>
#include <vector>
using namespace std;

// dynamic programming dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int m = 1e9+7;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i<=n; i++){
        for (int j=1; j<=6; j++){
            if (i-j >= 0) dp[i] = (dp[i]+dp[i-j]) % m;
        }
    }
    cout << dp[n];
    return 0;
}