#include <iostream>
#include <cmath>
using namespace std;
int cgcd;
int b, c, x, px;

int gcd(int aa, int bb){
    if (aa>bb) swap(aa, bb);

    if (aa==0) return bb;
    else if (aa==1) return 1;
    else return gcd(bb%aa, aa);
}

int main(){
    int n, q;
    cin >> n >> q;
    int a;
    cin >> a;
    if (n==1) {
        for (int i=1; i<=q; i++) cout << a+i << "\n";
    }else{
        cin >> b;
        if (n==2){
            cgcd = abs(b-a);
        }else{
            cin >> c;
            px  = c;
            cgcd = gcd(abs(b-a), abs(c-b));
            for (int i=3; i<n; i++){
                cin >> x;
                cgcd = gcd(abs(x-px), cgcd);
                px = x;
            }
        }

        for (int i=1; i<=q; i++) cout << gcd(a+i, cgcd) << "\n";
    }

}