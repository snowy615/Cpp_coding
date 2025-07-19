#include <iostream>
using namespace std;

int x;

int s(){
    if (x==0) return 1;
    else if (x%2==0) {
        x/=2;
        return s();
    }else {
        x-=1;
        return s()+1;
    }

}
int main(){
    cin >> x;
    int r = s();
    cout << r;
    return 0;
}