#include <iostream>
#include <cmath>

using namespace std;

double K = 0.99, ST = 1e5, ET = 1e-9, L=5;
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

    double T = ST; // temp
    double xx = 0, yy = 0; //grid coordinate
    double E = distance(xx, yy); //total dis
    double ans = E;
    while (T > ET){
        for (int i=1; i<=L; i++){
            double nx = xx+(double)(rand()*2-RAND_MAX) *T;
            double ny = yy+(double)(rand()*2-RAND_MAX)*T;
            double nE = distance(nx, ny);
            double dE = nE-E;
            if (dE < 0 || exp(-dE/T) > rand()/(double)RAND_MAX){
                xx=nx;
                yy=ny;
                E=nE;
                ans=min(ans, E);
            }
        }
        T *= K;
    }
    printf("%.0lf",ans);
}

//kmp algorithm https://www.youtube.com/watch?v=ynv7bbcSLKE