#include <iostream>
using namespace std;
const int N = 5e5+5;
int e[N], p[N];
int n, m, x, y, z;

void del(int x){
    if (e[x] == -1){
        e[p[x]] = -1;
    }else{
        e[p[x]] = e[x];
        p[e[x]] = p[x];
    }
}

void insert_f(int x, int y){
    e[x] = e[p[y]];
    p[x] = p[y];
    e[p[x]] = x;
    p[y] = x;
}

void insert_b(int x, int y){
    if (e[y] == -1){
        e[x] = -1;
        p[x] = y;
        e[y] = x;
    }else{
        e[x] = e[y];
        p[x] = y;
        e[y] = x;
        p[e[x]] = x;
    }

}
int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        e[i] = i+1;
        p[i] = i-1;
    }
    e[0]=1, e[n] = -1;

    for (int i=1; i<=m; i++){
        cin >> x >> y >> z;
        del(x);
        if (z) insert_f(x, y);
        else insert_b(x, y);
    }

    for (int i=e[0]; i != -1; i=e[i]) cout << i << " ";
    return 0;

}