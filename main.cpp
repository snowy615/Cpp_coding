#include <iostream>
#include <algorithm>
using namespace std;

//A = 0 C = 1 G = 2 T = 3

char in_c[4] = {'A', 'C', 'G', 'T'};

int a[1010], b[1010];
//int need[4] = {0, 0 ,0, 0};
int extra[4] = { 0, 0 ,0, 0};
int main(){
    int n;
    int cnt=0;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i<n; i++){
        int idx = find(in_c, in_c+4, s1[i]) - in_c;
        a[i] = idx;
        //cout << a[i] << " ";
        int bidx = find(in_c, in_c+4, s2[i]) - in_c;
        b[i] = bidx;
        //cout << b[i] << "\n";

        if (a[i]+b[i] != 3){
            //cout << "\nin " << a[i] << " " << b[i] << "\n";
            //cout << need[0] << " " << need[1] << " " << need[2] << " " << need[3] << "\n";
            //cout << extra[0] << " " << extra[1] << " " << extra[2] << " " << extra[3] << "\n";
            if (extra[3-a[i]]>0) {
                extra[3-a[i]] --;
                continue;
            }else{
                extra[a[i]] ++;
                cnt += 1;
            }

        }
    }
    cout << cnt;
}