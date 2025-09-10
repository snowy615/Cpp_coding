#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N =10;
int[N] prefix;
int solution(vector<int> dataSizes, int threshold) {

    vector<int> prefix;
    prefix.push_back(dataSizes[0]);
    for (int i=1; i<dataSizes.size(); i++){
        prefix.push_back(prefix[i-1]+dataSizes[i]);
    }
    int m = 0;
    for (int i=1; i<dataSizes.size(); i++){
        for (int j=0; j<i; j++){
            if (prefix[i]-2*max(prefix[i-j], 0)<=threshold) m = max(m, i-j+1);
        }
    }

    return 0;
}
