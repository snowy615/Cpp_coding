#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    for (int bb = 0; bb<n; bb++) {
        int lis_len;
        cin >> lis_len;
        int b [lis_len];
        int in = 0;
        for (int i = 0; i<lis_len; i++) {
            cin >> b[i];
            if (i>=1 && b[i] < b[i-1]){
                in = i;
            }
        }

        if (in != 0) cout << "YES\n" << 2 << "\n" <<  b[in-1] << " " << b[in] << "\n";
        else cout << "NO\n";

    }
}