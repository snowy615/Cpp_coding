#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 9*1e6+5;
vector<pair<int, int>> v;
vector<pair<int, int>> vo;
vector<int> d;
int n;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
        vo.push_back({a,b});
        d.push_back(0);
    }
    sort(v.begin(), v.begin()+n);
    reverse(v.begin(), v.end());
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (v[i] == vo[j]){
                d[i] = j;
            }
        }
    }
    int cnt = 0, tmp;
    for (int i=0; i<n; i++){
//        cout << d[i] << " ";
        tmp = 0;
        for (int j=0; j<i; j++){
            if (d[i] < d[j]) tmp ++;
        }
//        cout << tmp << " ";
        cnt += tmp;

    }
//    cout << "\n\n\n";
    cout << cnt;



}
