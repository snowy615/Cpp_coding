#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t, n, m;
    string s;
    cin >>t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        cin >> s;
        int num = 0;
        for (int j=0; j<s.size(); j++){
            if (s[j] - 'A' >= 0) num += (s[j] - 'A'+10)*pow(n, s.size()-j-1);
            else num += (s[j] - '0')*pow(n, s.size()-j-1);
        }
//        cout << "num " << num << "\n";
        int ss = 0;

        int lis[1000000];
        for (int j=0; j<100000; j++){
            if (num == 0) break;
            ss++;

            lis[j] = num%m;
            num /= m;
//            cout << lis[j] << " "<< num << "\n";
        }

        for (int j = ss-1; j>= 0; j--) {
            if (lis[j] <= 9) cout << lis[j];
            else cout << char('A' + lis[j]-10);
        }
        cout << "\n";

    }
}