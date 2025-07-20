#include <iostream>
#include <vector>
using namespace std;

string a;
int res;
vector<int> s(2000005, 0); // initialize vector with n+1 zeros

int main() {
    int n, m;
    cin >> n;
    cin >> a;

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1];
        if (i < n && a[i - 1] == '1' && a[i] == '0') {
            s[i]++;
        }
    }

    cin >> m;
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        res = s[r] - s[l - 1];

        if (r < n && a[r - 1] == '1' && a[r] == '0') {
            res--;
        }

        cout << res << "\n";
    }
}
