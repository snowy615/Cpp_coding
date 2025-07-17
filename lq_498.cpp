#include <iostream>
#include <iomanip> // for printing in format with 0.
using namespace std;

int main(){
    int y, m, d;
    string in;
    cin >> in;
    bool p = 0;
    y = stoi(in.substr(0, 4));
    m = stoi(in.substr(4, 2));
    d = stoi(in.substr(6, 2));
//    cout << y << m << d << "\n";

    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int yy = y; yy < 10000; yy++){
        int mm = 10*(yy%10) + int(yy/10)%10;
        int dd = (int(yy/100)%10) * 10 + int(yy/1000)%10;
        //cout << yy << " " << mm << " "<< dd << "\n";
        if (mm < 1 || mm>12 || dd < 1 || dd > 31) continue;
        if (dd > month[mm]) continue;
        if (mm == 2 && dd == 29){
            if (y%4!=0 || y%100==0 && y%400!=0)  continue;
        }
        if ((yy > y || (mm>m || (mm==m && dd>d)))){
            if (p==0){
                p = 1;
                cout << yy << setfill('0') << setw(2) << mm << setfill('0') << setw(2) << dd << "\n";
            }
            if (int(yy/1000)%10==int(yy/10)%10 && int(yy/100)%10==yy%10){
                cout << yy << setfill('0') << setw(2) << mm << setfill('0') << setw(2) << dd << "\n";
                break;
            }
        }

    }
}