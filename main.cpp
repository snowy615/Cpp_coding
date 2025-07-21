#include <iostream>
#include <cmath>
using namespace std;

bool is_pq(int num) {
    int q = sqrt(num);
    if (q * q == num) return true;
    return false;
}

int main(){
    cout << is_pq(12);
    cout << is_pq(11);
    cout << is_pq(10);
    cout << is_pq(1^0);
}