#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;
int main(){
    int cnt;
    int t, n, c, v;
    cin >> t;
    for (int i=1; i<=t; i++){
        cnt = 0;
        cin >> n >> c;
        for (int j=1; j<=n; j++){
            cin >> v;
            if (v>c) cnt ++;
            else{
                //cout << "v "<< int(log2(c/v)) << "\n";
                a.push_back(int(log2(c/v)));
            }
        }
        sort(a.begin(), a.end());
        while (!a.empty()){
            if (a[0]<0){
                cnt ++;
                a.erase(a.begin());
            }else{
                a.erase(a.begin());
                for (int j = 0; j<a.size(); j++) a[j] --;
            }

        }
        cout << cnt << "\n";
        //cout << "---------------\n";
    }

}