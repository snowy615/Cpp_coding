#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double K = 0.993, ST = 1e5, ET = 1e-9, L=2;
int n;
const int N = 1e3+5;
double x[N], y[N];

double distance(double nx, double ny){
    double d = 0;
    for (int i=1; i<=n; i++) d += sqrt(pow(nx-x[i], 2) + pow(ny-y[i], 2));
    return d;
}
int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i] >> y[i];

    double T = ST;
    double xx = 0, yy = 0;
    double E = distance(xx, yy);
    double ans = E;
    while (T > ET){
        for (int i=1; i<=L; i++){
            double nx = xx+(double)(rand()*2-RAND_MAX) *T;
            double ny = yy+(double)(rand()*2-RAND_MAX)*T;
            double ne = distance(nx, ny);
            double de = ne-E;
            if (de < 0 || exp(-de/T) > rand()/(double)RAND_MAX){
                xx=nx;
                yy=ny;
                E=ne;
                ans=min(ans, E);
            }
        }
        T *= K;
    }
   cout << round(ans);
}