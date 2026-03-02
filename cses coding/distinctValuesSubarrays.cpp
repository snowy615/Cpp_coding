#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) cin >> arr[i];

    set<int> window;
    int left = 0;
    long long total_subarrays = 0;

    for (int right = 0; right<n; right++){
        while (window.count(arr[right])) {
            window.erase(arr[left]);
            left++;
        }
        window.insert(arr[right]);
        total_subarrays += (right-left+1);
    }

    cout << total_subarrays;
    return 0;
}