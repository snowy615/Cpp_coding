#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int N = 1e5+5;
bitset<N> v;
vector<int> p;

void euler(int n){
    v[0] = true;
    v[1] = true;
    for (int i=2; i<=n; i++){
        if (!v[i]) p.push_back(i);
        for (int j=0; j<p.size() && i*p[j] <= n; j++){
            v[i*p[j]] = true;
            if (i%p[j] == 0) break;
        }
    }
}


signed main(){
    int n;
    n=1e9;
    euler(n);
    for (int i=0; i<p.size(); i++) cout << p[i] << ", ";
    return 0;
}
