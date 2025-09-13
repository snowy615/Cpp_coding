#include <iostream>
using namespace std;
int cgcd;
int b, c, x;

int gcd(int aa, int bb){
    if (aa>bb) swap(aa, bb);

    if (aa==0) return bb;
    else return gcd(aa, bb%aa);
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
            cgcd = b-a;
        }else{
            cin >> c;
            cgcd = gcd(b-a, c-b);
            for (int i=3; i<n; i++){
                cin >> x;
                cgcd = gcd(x, cgcd);
            }
        }

        for (int i=1; i<=q; i++) cout << gcd(a+i, cgcd) << "\n";
    }

}