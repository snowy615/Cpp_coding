#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> odd;
vector<int> even;

int main(){
    int n;
    cin >> n;
    int x;
    while (n--){
        cin >> x;
        if (x&1) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i=0; i<odd.size(); i++) cout << odd[i] << " ";
    for (int i=0; i<even.size(); i++) cout << even[i] << " ";

}