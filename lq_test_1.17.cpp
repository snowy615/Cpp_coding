#include <iostream>
#include <algorithm>
using namespace std;

priority_queue <int> c_max;
priority_queue <int, vector<int>, greater<int> > c_min;

int main(){
    int n, q, k, m, v;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> v;
        c_max.push(v);
        c_min.push(v);
    }

    for (int i=1; i<=q; i++){
        cin >> k >> m;
        int lf = 0;

        while (m && !c_max.empty() && !c_min.empty()){
            int cur_max = c_max.top();
            int cur_min = c_min.top();
            if (cur_min>=k || 2*k-cur_max <= cur_min) {
                lf += 2*k-cur_max;
                c_max.pop();
            } else{
                lf += cur_min;
                c_min.pop();
            }
            m --;
        }
        while (m && c_max.empty()){
            int cur_min = c_min.top();
            lf += cur_min;
            c_min.pop();
            m--;
        }
        while (m && c_min.empty()){
            int cur_max = c_max.top();
            lf += 2*k-cur_max;
            c_max.pop();
            m--;
        }
        cout << lf;
        return 0;
    }
}