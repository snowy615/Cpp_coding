#include <iostream>
using namespace std;
int a, b, c, n, ans = 0;
bool is_num(int x){
    if (x % a == 0 || x%b==0||x%c==0) return false;
    return true;
}
int main()
{
    cin >> n;
    cin >> a >> b >> c;
    for (int i = 1; i<=n; i++)
    {
        if (is_num(i)) ans ++;
    }
    cout << ans;
    return 0;
}
