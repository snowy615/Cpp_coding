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
   printf("%.0lf",ans);;
}



//
//#include <bits/stdc++.h>
//using namespace std;
//const int N=1e5+9,L=2;
//const double k=0.993,ET=1e-9;
//int n;
//double a[N][2],T=1e5,x=0,y=0;
//double getans(double x,double y)
//{
//    double ans=0;
//    for(int i=1;i<=n;i++)
//    {
//        ans+=sqrt((x-a[i][0])*(x-a[i][0])+(y-a[i][1])*(y-a[i][1]));
//    }
//    return ans;
//}
//double sa()
//{
//    double E=getans(x,y);
//    double ans=E;
//    while(T>ET)
//    {
//        for(int i=1;i<=L;i++)
//        {
//            double nx=x+(double)(rand()*2-RAND_MAX)*T;
//            double ny=y+(double)(rand()*2-RAND_MAX)*T;
//            double nE=getans(nx,ny);
//            double dE=nE-E;
//            if(dE<0||(exp(-dE/T)>(rand()/RAND_MAX)))
//            {
//                x=nx,y=ny;
//                E=nE;
//                ans=min(ans,E);
//            }
//        }
//        T*=k;
//    }
//    return ans;
//}
//int main()
//{
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1];
//    printf("%.0lf",sa());
//    return 0;
//}